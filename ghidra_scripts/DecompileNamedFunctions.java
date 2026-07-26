import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolType;

public class DecompileNamedFunctions extends GhidraScript {
    @Override
    public void run() throws Exception {
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        for (String name : getScriptArgs()) {
            boolean found = false;
            for (Symbol symbol : currentProgram.getSymbolTable().getSymbols(name)) {
                if (symbol.getSymbolType() != SymbolType.FUNCTION) {
                    continue;
                }
                Function function = getFunctionAt(symbol.getAddress());
                if (function == null) {
                    continue;
                }
                found = true;
                println("FUNCTION " + function.getName() + " at " + function.getEntryPoint());
                DecompileResults result =
                    decompiler.decompileFunction(function, 180, monitor);
                if (result.decompileCompleted()) {
                    println(result.getDecompiledFunction().getC());
                }
            }
            if (!found) {
                println("NOT_FOUND " + name);
            }
        }
        decompiler.dispose();
    }
}
