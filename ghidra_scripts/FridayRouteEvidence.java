// Emit conservative, function-local route/sink evidence as JSON Lines.
// A record means only that the decompiled function contains both strings; it
// does not claim that attacker input reaches the sink.

import java.io.File;
import java.io.FileWriter;
import java.util.LinkedHashSet;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;

public class FridayRouteEvidence extends GhidraScript {
    private static final Pattern ROUTE = Pattern.compile(
        "(?i)("
            + "(?:/[A-Za-z0-9_.~!$&'()*+,;=:@%-]+){1,12}(?:\\?(?:[A-Za-z0-9_.~!$&'()*+,;=:@%/?-]+)?)?"
            + "|[A-Za-z0-9_./-]{1,160}(?:\\.cgi|\\.asp|\\.html?|\\.lua|cgi-bin/[A-Za-z0-9_./-]+)"
            + "|urn:[A-Za-z0-9_.:-]{3,160}"
            + ")"
    );
    private static final Pattern SINK = Pattern.compile(
        "(?i)\\b(system|doSystem|popen|execve|execl|execv|strcpy|strcat|sprintf|vsprintf|"
            + "memcpy|memmove|scanf|sscanf|fopen|open|rename|symlink|nvram_set|uci_set)\\s*\\("
    );
    private static final Pattern SOURCE = Pattern.compile(
        "(?i)\\b(QUERY_STRING|CONTENT_LENGTH|HTTP_COOKIE|getenv|websGetVar|cgiGetValue|"
            + "nvram_get|uci_get|ubus|recv|recvfrom|read)\\s*\\("
    );
    private static final Pattern AUTH = Pattern.compile(
        "(?i)\\b(auth(?:orize)?|login|session|cookie|token|csrf|password|passwd|no[_ -]?auth|unauth)\\b"
    );

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 1) {
            printerr("FridayRouteEvidence requires one output JSONL path");
            return;
        }
        File output = new File(args[0]);
        File parent = output.getParentFile();
        if (parent != null) parent.mkdirs();

        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        try (FileWriter writer = new FileWriter(output, false)) {
            FunctionIterator functions = currentProgram.getFunctionManager().getFunctions(true);
            for (Function function : functions) {
                if (monitor.isCancelled()) break;
                if (function.isExternal() || function.isThunk()) continue;
                DecompileResults result = decompiler.decompileFunction(function, 30, monitor);
                if (!result.decompileCompleted() || result.getDecompiledFunction() == null) continue;
                String code = result.getDecompiledFunction().getC();
                Set<String> routes = matches(ROUTE, code);
                Set<String> sinks = matches(SINK, code);
                Set<String> sources = matches(SOURCE, code);
                Set<String> authMarkers = matches(AUTH, code);
                for (String route : routes) {
                    for (String sink : sinks) {
                        writer.write("{\"binary\":\"" + json(currentProgram.getName()) +
                            "\",\"function\":\"" + json(function.getName()) +
                            "\",\"address\":\"" + json(function.getEntryPoint().toString()) +
                            "\",\"route\":\"" + json(route) +
                            "\",\"sink\":\"" + json(normalizeSink(sink)) +
                            "\",\"sources\":\"" + json(String.join(",", sources)) +
                            "\",\"auth_markers\":\"" + json(String.join(",", authMarkers)) +
                            "\",\"correlation\":\"function-local-co-location\"}\n");
                    }
                }
            }
        } finally {
            decompiler.dispose();
        }
    }

    private static Set<String> matches(Pattern pattern, String text) {
        Set<String> values = new LinkedHashSet<>();
        Matcher matcher = pattern.matcher(text);
        while (matcher.find() && values.size() < 200) values.add(matcher.group(1));
        return values;
    }

    private static String normalizeSink(String sink) {
        String value = sink.toLowerCase();
        if (value.equals("dosystem")) return "system";
        if (value.startsWith("exec")) return "exec";
        if (value.equals("strcpy") || value.equals("strcat") || value.contains("sprintf")) return "unsafe_copy";
        if (value.equals("memcpy") || value.equals("memmove") || value.equals("scanf") || value.equals("sscanf")) return "memory_operation";
        if (value.equals("fopen") || value.equals("open") || value.equals("rename") || value.equals("symlink")) return "file_write";
        if (value.equals("nvram_set") || value.equals("uci_set")) return "configuration_write";
        return value;
    }

    private static String json(String value) {
        return value.replace("\\", "\\\\").replace("\"", "\\\"")
            .replace("\n", "\\n").replace("\r", "\\r").replace("\t", "\\t");
    }
}
