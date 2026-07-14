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
        "(?i)([A-Za-z0-9_./-]{1,160}(?:\\.cgi|cgi-bin/[A-Za-z0-9_./-]+))"
    );
    private static final Pattern SINK = Pattern.compile(
        "(?i)\\b(system|doSystem|popen|execve|execl|execv|strcpy|strcat|sprintf|vsprintf|fopen|rename|symlink)\\s*\\("
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
                for (String route : routes) {
                    for (String sink : sinks) {
                        writer.write("{\"binary\":\"" + json(currentProgram.getName()) +
                            "\",\"function\":\"" + json(function.getName()) +
                            "\",\"address\":\"" + json(function.getEntryPoint().toString()) +
                            "\",\"route\":\"" + json(route) +
                            "\",\"sink\":\"" + json(normalizeSink(sink)) + "\"}\n");
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
        if (value.equals("fopen") || value.equals("rename") || value.equals("symlink")) return "file_write";
        return value;
    }

    private static String json(String value) {
        return value.replace("\\", "\\\\").replace("\"", "\\\"")
            .replace("\n", "\\n").replace("\r", "\\r").replace("\t", "\\t");
    }
}
