// Verify that every discovered function was presented to Ghidra's decompiler.
// The compact JSON receipt avoids retaining many gigabytes of pseudocode while
// still making exhaustive campaign coverage auditable.

import java.io.File;
import java.io.FileWriter;
import java.util.LinkedHashSet;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;

public class FridayDecompileReceipt extends GhidraScript {
    private static final int SECURITY_SCHEMA = 4;
    private static final int[] DECOMPILE_TIMEOUTS = {60, 180, 600};
    private static final Pattern ROUTE = Pattern.compile("(?i)((?:/[A-Za-z0-9][A-Za-z0-9_.~!$&'()+,;=:@%-]*){1,12}|[A-Za-z0-9_./-]{1,160}(?:\\.cgi|\\.asp|\\.html?|\\.lua)|cgi-bin/[A-Za-z0-9_./-]+)");
    private static final Pattern SINK = Pattern.compile("(?i)\\b(system|doSystem|popen|execve|execl|execv|strcpy|strcat|sprintf|vsprintf|memcpy|memmove|scanf|sscanf|fopen|open|rename|symlink|nvram_set|uci_set)\\s*\\(");
    private static final Pattern SOURCE = Pattern.compile("(?i)\\b(getenv|websGetVar|cgiGetValue|recv|recvfrom|read|fgets|nvram_get|uci_get|ubus)\\s*\\(");
    private static final Pattern AUTH = Pattern.compile("(?i)\\b(auth(?:orize|enticate)?|login|session|cookie|token|csrf|password|passwd|no[_ -]?auth|unauth)\\b");

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 2) throw new IllegalArgumentException("receipt and evidence paths required");
        File output = new File(args[0]);
        File evidence = new File(args[1]);
        if (output.getParentFile() != null) output.getParentFile().mkdirs();
        if (evidence.getParentFile() != null) evidence.getParentFile().mkdirs();
        long discovered = 0, attempted = 0, succeeded = 0, failed = 0, timedOut = 0;
        long retryAttempts = 0;
        long candidateFunctions = 0, evidenceRecords = 0;
        List<Function> pending = new ArrayList<>();
        DecompInterface decompiler = new DecompInterface();
        if (!decompiler.openProgram(currentProgram)) {
            throw new IllegalStateException("decompiler could not open program");
        }
        try (FileWriter evidenceWriter = new FileWriter(evidence, false)) {
            FunctionIterator functions = currentProgram.getFunctionManager().getFunctions(true);
            for (Function function : functions) {
                if (monitor.isCancelled()) break;
                if (function.isExternal() || function.isThunk()) continue;
                discovered++;
                pending.add(function);
            }
            attempted = discovered;
            for (int pass = 0; pass < DECOMPILE_TIMEOUTS.length && !pending.isEmpty(); pass++) {
                List<Function> retry = new ArrayList<>();
                for (Function function : pending) {
                    if (monitor.isCancelled()) {
                        retry.add(function);
                        continue;
                    }
                    if (pass > 0) retryAttempts++;
                    DecompileResults result = decompiler.decompileFunction(
                        function, DECOMPILE_TIMEOUTS[pass], monitor);
                    if (result.decompileCompleted() && result.getDecompiledFunction() != null) {
                        succeeded++;
                        String code = result.getDecompiledFunction().getC();
                        Set<String> sinks = matches(SINK, code, 40);
                        sinks.removeIf(value -> value.equalsIgnoreCase(function.getName()));
                        Set<String> sources = matches(SOURCE, code, 40);
                        Set<String> routes = matches(ROUTE, code, 40);
                        Set<String> auth = matches(AUTH, code, 40);
                        if (!sinks.isEmpty() && (!sources.isEmpty() || !routes.isEmpty())) {
                            candidateFunctions++;
                            evidenceWriter.write("{\"schema\":" + SECURITY_SCHEMA
                                + ",\"binary\":\"" + json(currentProgram.getName())
                                + "\",\"function\":\"" + json(function.getName())
                                + "\",\"address\":\"" + json(function.getEntryPoint().toString())
                                + "\",\"sinks\":" + jsonArray(sinks)
                                + ",\"sources\":" + jsonArray(sources)
                                + ",\"routes\":" + jsonArray(routes)
                                + ",\"auth_markers\":" + jsonArray(auth)
                                + ",\"classification\":\"potential-function-local-correlation\"}\n");
                            evidenceRecords++;
                        }
                    }
                    else {
                        retry.add(function);
                        if (pass == DECOMPILE_TIMEOUTS.length - 1 && result.isTimedOut()) timedOut++;
                    }
                }
                pending = retry;
            }
            failed = pending.size();
        } finally {
            decompiler.dispose();
        }
        try (FileWriter writer = new FileWriter(output, false)) {
            writer.write("{\n");
            writer.write("  \"program\": \"" + json(currentProgram.getName()) + "\",\n");
            writer.write("  \"security_schema\": " + SECURITY_SCHEMA + ",\n");
            writer.write("  \"functions_discovered\": " + discovered + ",\n");
            writer.write("  \"functions_attempted\": " + attempted + ",\n");
            writer.write("  \"functions_succeeded\": " + succeeded + ",\n");
            writer.write("  \"functions_failed\": " + failed + ",\n");
            writer.write("  \"functions_timed_out\": " + timedOut + ",\n");
            writer.write("  \"retry_attempts\": " + retryAttempts + ",\n");
            writer.write("  \"coverage_status\": \"" + (failed == 0 ? "complete" : "partial") + "\",\n");
            writer.write("  \"candidate_functions\": " + candidateFunctions + ",\n");
            writer.write("  \"evidence_records\": " + evidenceRecords + ",\n");
            writer.write("  \"evidence_path\": \"" + json(evidence.getAbsolutePath()) + "\"\n");
            writer.write("}\n");
        }
        if (attempted != discovered || monitor.isCancelled()) {
            throw new IllegalStateException("incomplete decompilation: discovered=" + discovered
                + " attempted=" + attempted + " failed=" + failed);
        }
    }

    private static Set<String> matches(Pattern pattern, String text, int limit) {
        Set<String> values = new LinkedHashSet<>();
        Matcher matcher = pattern.matcher(text);
        while (matcher.find() && values.size() < limit) values.add(matcher.group(1));
        return values;
    }

    private static String jsonArray(Set<String> values) {
        StringBuilder result = new StringBuilder("[");
        boolean first = true;
        for (String value : values) {
            if (!first) result.append(',');
            result.append('"').append(json(value)).append('"');
            first = false;
        }
        return result.append(']').toString();
    }

    private static String json(String value) {
        return value.replace("\\", "\\\\").replace("\"", "\\\"")
            .replace("\n", "\\n").replace("\r", "\\r").replace("\t", "\\t");
    }
}
