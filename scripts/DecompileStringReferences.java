import ghidra.app.decompiler.DecompInterface;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.StringDataInstance;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.symbol.Reference;
import java.util.HashSet;
import java.util.Set;

/**
 * Headless post-script that finds strings containing any supplied token and
 * decompiles every function that directly references those strings.
 */
public class DecompileStringReferences extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] needles = getScriptArgs();
        Listing listing = currentProgram.getListing();
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        Set<Address> emitted = new HashSet<>();

        for (Data data : listing.getDefinedData(true)) {
            StringDataInstance instance = StringDataInstance.getStringDataInstance(data);
            if (instance == null) {
                continue;
            }
            String value = instance.getStringValue();
            if (value == null) {
                continue;
            }
            for (String needle : needles) {
                if (!value.contains(needle)) {
                    continue;
                }
                println("STRING " + data.getAddress() + " " + value);
                for (Reference reference :
                        currentProgram.getReferenceManager().getReferencesTo(data.getAddress())) {
                    Function function = getFunctionContaining(reference.getFromAddress());
                    if (function == null || !emitted.add(function.getEntryPoint())) {
                        continue;
                    }
                    println("===== " + function.getName(true) + " @ "
                            + function.getEntryPoint() + " =====");
                    println(decompiler.decompileFunction(function, 120, monitor)
                            .getDecompiledFunction().getC());
                }
            }
        }
        decompiler.dispose();
    }
}
