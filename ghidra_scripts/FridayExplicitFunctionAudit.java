// Create/decompile functions at explicit entry points missed by auto-analysis.
import java.io.File;
import java.io.FileWriter;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class FridayExplicitFunctionAudit extends GhidraScript {
    @Override public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) throw new IllegalArgumentException("output and entry addresses required");
        File output = new File(args[0]);
        if (output.getParentFile() != null) output.getParentFile().mkdirs();
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        try (FileWriter writer = new FileWriter(output, false)) {
            for (int i = 1; i < args.length; i++) {
                Address entry = toAddr(args[i]);
                Function function = getFunctionAt(entry);
                if (function == null) {
                    disassemble(entry);
                    function = createFunction(entry, null);
                }
                writer.write("\n===== ENTRY " + entry + " =====\n");
                if (function == null) {
                    writer.write("FUNCTION_CREATION_FAILED\n");
                    continue;
                }
                writer.write("===== FUNCTION " + function.getName() + " @ " +
                    function.getEntryPoint() + " =====\n");
                DecompileResults result = decompiler.decompileFunction(function, 120, monitor);
                writer.write(result.decompileCompleted() && result.getDecompiledFunction() != null
                    ? result.getDecompiledFunction().getC() : "DECOMPILE_FAILED\n");
            }
        } finally {
            decompiler.dispose();
        }
    }
}
