// Decompile acos_service functions that reference UPnP and firewall startup strings.
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Reference;

import java.nio.charset.StandardCharsets;
import java.util.HashSet;

public class GhidraRs700Startup extends GhidraScript {
    private final String[] targets = {
        "upnpd", "arno-iptables-firewall", "c_arno-iptables-firewall",
        "arno_nat_cli_new_design start", "start_nat",
        "upnp_turn_on", "router_disable", "remote_syslog_enable"
    };

    @Override
    public void run() throws Exception {
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        HashSet<String> seen = new HashSet<String>();
        Memory memory = currentProgram.getMemory();
        for (String target : targets) {
            println("\n===== TARGET " + target + " =====");
            byte[] needle = target.getBytes(StandardCharsets.US_ASCII);
            for (MemoryBlock block : memory.getBlocks()) {
                if (!block.isInitialized() || block.getSize() > Integer.MAX_VALUE) continue;
                byte[] bytes = new byte[(int) block.getSize()];
                try {
                    block.getBytes(block.getStart(), bytes);
                } catch (Exception error) {
                    continue;
                }
                for (int offset = indexOf(bytes, needle, 0); offset >= 0;
                     offset = indexOf(bytes, needle, offset + 1)) {
                    Address address = block.getStart().add(offset);
                    println("STRING " + target + " at " + address);
                    for (Reference reference : getReferencesTo(address)) {
                        Function function = getFunctionContaining(reference.getFromAddress());
                        println("  REF " + reference.getFromAddress() + " " +
                            (function == null ? "null" : function.getName() + "@" + function.getEntryPoint()));
                        if (function != null && seen.add(function.getEntryPoint().toString())) {
                            decompile(decompiler, function);
                            for (Reference callerReference :
                                 getReferencesTo(function.getEntryPoint())) {
                                Function caller =
                                    getFunctionContaining(callerReference.getFromAddress());
                                if (caller != null &&
                                    seen.add(caller.getEntryPoint().toString())) {
                                    println("  CALLER REF " +
                                        callerReference.getFromAddress());
                                    decompile(decompiler, caller);
                                }
                            }
                        }
                    }
                }
            }
        }
        decompiler.dispose();
    }

    private void decompile(DecompInterface decompiler, Function function) {
        println("----- FUNCTION " + function.getName() + " " +
            function.getEntryPoint() + " -----");
        DecompileResults result =
            decompiler.decompileFunction(function, 120, monitor);
        println(result != null && result.decompileCompleted()
            ? result.getDecompiledFunction().getC()
            : "DECOMPILE_FAILED");
    }

    private int indexOf(byte[] bytes, byte[] needle, int start) {
        outer:
        for (int offset = start; offset <= bytes.length - needle.length; offset++) {
            for (int index = 0; index < needle.length; index++) {
                if (bytes[offset + index] != needle[index]) continue outer;
            }
            return offset;
        }
        return -1;
    }
}
