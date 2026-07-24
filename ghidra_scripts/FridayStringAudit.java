// Dump functions that reference requested strings for focused reachability review.
import java.io.File;
import java.io.FileWriter;
import java.nio.charset.StandardCharsets;
import java.util.LinkedHashSet;
import java.util.Set;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Reference;

public class FridayStringAudit extends GhidraScript {
    @Override public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) throw new IllegalArgumentException("output and strings required");
        File output = new File(args[0]);
        if (output.getParentFile() != null) output.getParentFile().mkdirs();
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        Set<String> seen = new LinkedHashSet<>();
        try (FileWriter writer = new FileWriter(output, false)) {
            for (int targetIndex = 1; targetIndex < args.length; targetIndex++) {
                String target = args[targetIndex];
                byte[] needle = target.getBytes(StandardCharsets.US_ASCII);
                writer.write("\n===== TARGET " + target + " =====\n");
                for (MemoryBlock block : currentProgram.getMemory().getBlocks()) {
                    if (!block.isInitialized() || block.getSize() > Integer.MAX_VALUE) continue;
                    byte[] hay = new byte[(int)block.getSize()];
                    try { block.getBytes(block.getStart(), hay); } catch (Exception e) { continue; }
                    for (int at = indexOf(hay, needle, 0); at >= 0; at = indexOf(hay, needle, at + 1)) {
                        Address address = block.getStart().add(at);
                        for (Reference reference : getReferencesTo(address)) {
                            Function function = getFunctionContaining(reference.getFromAddress());
                            if (function == null || !seen.add(function.getEntryPoint().toString())) continue;
                            writer.write("\n===== FUNCTION " + function.getName() + " @ " + function.getEntryPoint() + " =====\n");
                            DecompileResults result = decompiler.decompileFunction(function, 120, monitor);
                            writer.write(result.decompileCompleted() && result.getDecompiledFunction() != null
                                ? result.getDecompiledFunction().getC() : "DECOMPILE_FAILED\n");
                        }
                    }
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
}
