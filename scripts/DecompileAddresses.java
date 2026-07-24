// Ghidra headless post-script: decompile functions containing supplied addresses.
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class DecompileAddresses extends GhidraScript {
    @Override
    public void run() throws Exception {
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        for (String value : getScriptArgs()) {
            Address address = toAddr(value);
            Function function = getFunctionContaining(address);
            if (function == null) {
                println("NO_FUNCTION " + value);
                continue;
            }
            println("===== " + function.getName(true) + " @ " + function.getEntryPoint() + " =====");
            println(decompiler.decompileFunction(function, 120, monitor)
                    .getDecompiledFunction().getC());
        }
        decompiler.dispose();
    }
}
