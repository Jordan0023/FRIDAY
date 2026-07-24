// Follow string references through data tables and decompile the code that uses them.
import java.io.File;
import java.io.FileWriter;
import java.nio.charset.StandardCharsets;
import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Set;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Reference;

public class FridayRecursiveStringAudit extends GhidraScript {
    @Override public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) throw new IllegalArgumentException("output and strings required");
        File output = new File(args[0]);
        if (output.getParentFile() != null) output.getParentFile().mkdirs();
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        try (FileWriter writer = new FileWriter(output, false)) {
            for (int targetIndex = 1; targetIndex < args.length; targetIndex++) {
                String target = args[targetIndex];
                byte[] needle = target.getBytes(StandardCharsets.US_ASCII);
                Set<Function> functions = new LinkedHashSet<>();
                Set<Address> visited = new HashSet<>();
                ArrayDeque<AddressDepth> queue = new ArrayDeque<>();
                writer.write("\n===== TARGET " + target + " =====\n");
                for (MemoryBlock block : currentProgram.getMemory().getBlocks()) {
                    if (!block.isInitialized() || block.getSize() > Integer.MAX_VALUE) continue;
                    byte[] hay = new byte[(int)block.getSize()];
                    try { block.getBytes(block.getStart(), hay); } catch (Exception e) { continue; }
                    for (int at = indexOf(hay, needle, 0); at >= 0; at = indexOf(hay, needle, at + 1)) {
                        Address address = block.getStart().add(at);
                        writer.write("STRING " + address + "\n");
                        queue.add(new AddressDepth(address, 0));
                    }
                }
                while (!queue.isEmpty()) {
                    AddressDepth item = queue.removeFirst();
                    if (!visited.add(item.address) || item.depth > 3) continue;
                    for (Reference reference : getReferencesTo(item.address)) {
                        Address from = reference.getFromAddress();
                        writer.write("REF depth=" + item.depth + " from=" + from + " to=" + item.address + "\n");
                        Function function = getFunctionContaining(from);
                        if (function != null) functions.add(function);
                        else queue.add(new AddressDepth(from, item.depth + 1));
                    }
                }
                for (Function function : functions) {
                    writer.write("\n===== FUNCTION " + function.getName() + " @ " + function.getEntryPoint() + " =====\n");
                    DecompileResults result = decompiler.decompileFunction(function, 120, monitor);
                    writer.write(result.decompileCompleted() && result.getDecompiledFunction() != null
                        ? result.getDecompiledFunction().getC() : "DECOMPILE_FAILED\n");
                }
            }
        } finally { decompiler.dispose(); }
    }

    private int indexOf(byte[] hay, byte[] needle, int start) {
        outer: for (int i = start; i <= hay.length - needle.length; i++) {
            for (int j = 0; j < needle.length; j++) if (hay[i+j] != needle[j]) continue outer;
            return i;
        }
        return -1;
    }

    private static class AddressDepth {
        final Address address;
        final int depth;
        AddressDepth(Address address, int depth) {
            this.address = address;
            this.depth = depth;
        }
    }
}
