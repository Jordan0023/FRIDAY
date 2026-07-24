import ghidra.app.decompiler.DecompInterface;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import java.util.HashSet;
import java.util.Set;

public class DecompileDataReferences extends GhidraScript {
    @Override
    public void run() throws Exception {
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        Set<Address> emitted = new HashSet<>();
        for (String value : getScriptArgs()) {
            Address target = toAddr(value);
            for (Reference reference :
                    currentProgram.getReferenceManager().getReferencesTo(target)) {
                Function function = getFunctionContaining(reference.getFromAddress());
                if (function == null || !emitted.add(function.getEntryPoint()))
                    continue;
                println("===== " + function.getName(true) + " @ "
                        + function.getEntryPoint() + " references " + value + " =====");
                println(decompiler.decompileFunction(function, 120, monitor)
                        .getDecompiledFunction().getC());
            }
        }
        decompiler.dispose();
    }
}
