// Ghidra headless post-script: decompile functions at supplied addresses.
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class DecompileFunctionsByAddress extends GhidraScript {
    @Override
    public void run() throws Exception {
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        for (String text : getScriptArgs()) {
            Address address = toAddr(text);
            Function function = getFunctionAt(address);
            if (function == null) {
                disassemble(address);
                function = createFunction(address, null);
            }
            if (function == null) {
                function = getFunctionContaining(address);
            }
            if (function == null) {
                println("NO_FUNCTION " + text);
                continue;
            }
            println("FUNCTION " + function.getName() + " at " +
                function.getEntryPoint());
            DecompileResults result =
                decompiler.decompileFunction(function, 300, monitor);
            if (result.decompileCompleted()) {
                println(result.getDecompiledFunction().getC());
            } else {
                println("DECOMPILE_FAILED " + result.getErrorMessage());
            }
        }
        decompiler.dispose();
    }
}
