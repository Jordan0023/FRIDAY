// Retain focused pseudocode and caller evidence for a named-function security audit.
import java.io.File;
import java.io.FileWriter;
import java.util.LinkedHashSet;
import java.util.Set;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.symbol.Reference;

public class FridayTargetAudit extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) throw new IllegalArgumentException("output and function names required");
        File output = new File(args[0]);
        if (output.getParentFile() != null) output.getParentFile().mkdirs();
        Set<Function> selected = new LinkedHashSet<>();
        FunctionIterator functions = currentProgram.getFunctionManager().getFunctions(true);
        while (functions.hasNext()) {
            Function f = functions.next();
            for (int i = 1; i < args.length; i++) {
                if (f.getName().equals(args[i])) selected.add(f);
            }
        }
        Set<Function> expanded = new LinkedHashSet<>(selected);
        for (Function target : selected) {
            for (Reference ref : getReferencesTo(target.getEntryPoint())) {
                Function caller = getFunctionContaining(ref.getFromAddress());
                if (caller != null) expanded.add(caller);
            }
        }
        DecompInterface decompiler = new DecompInterface();
        if (!decompiler.openProgram(currentProgram)) throw new IllegalStateException("cannot open program");
        try (FileWriter writer = new FileWriter(output, false)) {
            for (Function f : expanded) {
                writer.write("\n===== FUNCTION " + f.getName() + " @ " + f.getEntryPoint() + " =====\n");
                DecompileResults result = decompiler.decompileFunction(f, 120, monitor);
                if (result.decompileCompleted() && result.getDecompiledFunction() != null)
                    writer.write(result.getDecompiledFunction().getC());
                else writer.write("DECOMPILE_FAILED\n");
            }
        } finally {
            decompiler.dispose();
        }
    }
}
