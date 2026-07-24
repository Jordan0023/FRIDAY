// Retain pseudocode for every discovered function in a small target binary.
import java.io.File;
import java.io.FileWriter;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;

public class FridayFullPseudocode extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 1) throw new IllegalArgumentException("output path required");
        File output = new File(args[0]);
        if (output.getParentFile() != null) output.getParentFile().mkdirs();
        DecompInterface decompiler = new DecompInterface();
        if (!decompiler.openProgram(currentProgram)) {
            throw new IllegalStateException("cannot open program");
        }
        try (FileWriter writer = new FileWriter(output, false)) {
            FunctionIterator functions =
                currentProgram.getFunctionManager().getFunctions(true);
            while (functions.hasNext() && !monitor.isCancelled()) {
                Function function = functions.next();
                if (function.isExternal()) continue;
                writer.write("\n===== FUNCTION " + function.getName() + " @ " +
                    function.getEntryPoint() + " =====\n");
                DecompileResults result =
                    decompiler.decompileFunction(function, 120, monitor);
                writer.write(result.decompileCompleted() &&
                    result.getDecompiledFunction() != null
                    ? result.getDecompiledFunction().getC()
                    : "DECOMPILE_FAILED\n");
            }
        } finally {
            decompiler.dispose();
        }
    }
}
