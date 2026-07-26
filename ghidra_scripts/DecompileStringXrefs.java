// Ghidra headless post-script: decompile functions referencing supplied strings.
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Reference;
import java.nio.charset.StandardCharsets;
import java.util.HashSet;

public class DecompileStringXrefs extends GhidraScript {
    @Override
    public void run() throws Exception {
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        HashSet<String> seen = new HashSet<>();
        for (String target : getScriptArgs()) {
            byte[] needle = target.getBytes(StandardCharsets.US_ASCII);
            for (MemoryBlock block : currentProgram.getMemory().getBlocks()) {
                if (!block.isInitialized() || block.getSize() > Integer.MAX_VALUE) {
                    continue;
                }
                byte[] bytes = new byte[(int) block.getSize()];
                block.getBytes(block.getStart(), bytes);
                for (int offset = 0; offset <= bytes.length - needle.length; offset++) {
                    int index = 0;
                    while (index < needle.length && bytes[offset + index] == needle[index]) {
                        index++;
                    }
                    if (index != needle.length) {
                        continue;
                    }
                    Address stringAddress = block.getStart().add(offset);
                    println("TARGET " + target + " at " + stringAddress);
                    for (Reference reference : getReferencesTo(stringAddress)) {
                        Function function = getFunctionContaining(reference.getFromAddress());
                        if (function == null ||
                            !seen.add(function.getEntryPoint().toString())) {
                            continue;
                        }
                        println("FUNCTION " + function.getName() + " at " +
                            function.getEntryPoint());
                        DecompileResults result =
                            decompiler.decompileFunction(function, 180, monitor);
                        if (result.decompileCompleted()) {
                            println(result.getDecompiledFunction().getC());
                        }
                    }
                }
            }
        }
        decompiler.dispose();
    }
}
