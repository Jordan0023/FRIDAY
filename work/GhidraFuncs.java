import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class GhidraFuncs extends GhidraScript {
    private final String[] addrs = {
        "00087454", "00087618", "0008778c", "000878f0",
        "000b4cf8", "000b5e7c", "000b62b4",
        "00045268", "00046740", "00053ca4", "00053b38", "00074e1c"
    };

    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        for (String a : addrs) {
            Address addr = toAddr(a);
            Function f = getFunctionAt(addr);
            if (f == null) f = getFunctionContaining(addr);
            println("\n===== FUNC_AT " + a + " " + (f == null ? "null" : f.getName()+"@"+f.getEntryPoint()) + " =====");
            if (f == null) continue;
            DecompileResults res = ifc.decompileFunction(f, 90, monitor);
            if (res != null && res.decompileCompleted()) {
                println(res.getDecompiledFunction().getC());
            } else {
                println("DECOMPILE_FAILED");
            }
        }
    }
}
