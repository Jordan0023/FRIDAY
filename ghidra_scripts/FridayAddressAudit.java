// Decompile the functions containing specified addresses.
import java.io.File;
import java.io.FileWriter;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;

public class FridayAddressAudit extends GhidraScript {
    @Override public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) throw new IllegalArgumentException("output and addresses required");
        File output = new File(args[0]);
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        try (FileWriter writer = new FileWriter(output, false)) {
            for (int i = 1; i < args.length; i++) {
                Address address = toAddr(args[i]);
                Function function = getFunctionContaining(address);
                writer.write("\n===== ADDRESS " + address + " FUNCTION " +
                    (function == null ? "NONE" : function.getName()) + " =====\n");
                if (function != null) {
                    DecompileResults result = decompiler.decompileFunction(function, 120, monitor);
                    writer.write(result.decompileCompleted() && result.getDecompiledFunction() != null
                        ? result.getDecompiledFunction().getC() : "DECOMPILE_FAILED\n");
                }
                for (Reference reference : getReferencesTo(address)) {
                    Function owner = getFunctionContaining(reference.getFromAddress());
                    writer.write("REFERENCE " + reference.getFromAddress() + " OWNER " +
                        (owner == null ? "NONE" : owner.getName()) + "\n");
                    if (owner != null) {
                        DecompileResults result = decompiler.decompileFunction(owner, 120, monitor);
                        writer.write(result.decompileCompleted() && result.getDecompiledFunction() != null
                            ? result.getDecompiledFunction().getC() : "DECOMPILE_FAILED\n");
                    }
                }
            }
        } finally { decompiler.dispose(); }
    }
}
