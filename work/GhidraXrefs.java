//Dump decompiled functions that reference selected strings.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Reference;

import java.nio.charset.StandardCharsets;
import java.util.HashSet;

public class GhidraXrefs extends GhidraScript {
    private final String[] targets = {
        "RMT_invite.cgi", "RMT_invite", "device_name2",
        "genieping.cgi", "genieping2.cgi", "genieping3.cgi", "genieping4.cgi",
        "rccommand.cgi", "rccommand_test.cgi", "newdebug.cgi",
        "openvpn_hidden.cgi", "readycloud_control.cgi", "targetTimezone",
        "burn_sw_feature 2>/tmp/sw_feature.txt"
    };

    @Override
    public void run() throws Exception {
        DecompInterface ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        HashSet<String> seen = new HashSet<String>();
        Memory mem = currentProgram.getMemory();

        for (String target : targets) {
            println("\n===== TARGET " + target + " =====");
            byte[] needle = target.getBytes(StandardCharsets.US_ASCII);
            for (MemoryBlock block : mem.getBlocks()) {
                if (!block.isInitialized()) continue;
                long sizeLong = block.getSize();
                if (sizeLong > Integer.MAX_VALUE) continue;
                byte[] hay = new byte[(int) sizeLong];
                try {
                    block.getBytes(block.getStart(), hay);
                } catch (Exception e) {
                    continue;
                }
                for (int idx = indexOf(hay, needle, 0); idx >= 0; idx = indexOf(hay, needle, idx + 1)) {
                    Address addr = block.getStart().add(idx);
                    println("STRING " + target + " at " + addr);
                    Reference[] references = getReferencesTo(addr);
                    for (Reference ref : references) {
                        Function f = getFunctionContaining(ref.getFromAddress());
                        println("  REF from " + ref.getFromAddress() + " func=" + (f == null ? "null" : f.getName() + "@" + f.getEntryPoint()));
                        if (f != null && seen.add(f.getEntryPoint().toString())) {
                            println("----- FUNC " + f.getName() + " " + f.getEntryPoint() + " -----");
                            DecompileResults res = ifc.decompileFunction(f, 60, monitor);
                            if (res != null && res.decompileCompleted()) {
                                println(res.getDecompiledFunction().getC());
                            } else {
                                println("DECOMPILE_FAILED");
                            }
                        }
                    }
                }
            }
        }
    }

    private int indexOf(byte[] hay, byte[] needle, int start) {
        outer:
        for (int i = start; i <= hay.length - needle.length; i++) {
            for (int j = 0; j < needle.length; j++) {
                if (hay[i + j] != needle[j]) continue outer;
            }
            return i;
        }
        return -1;
    }
}
