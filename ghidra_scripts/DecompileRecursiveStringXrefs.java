// Ghidra headless post-script: recursively follow data xrefs to target strings.
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Reference;
import java.nio.charset.StandardCharsets;
import java.util.HashSet;
import java.util.LinkedHashSet;

public class DecompileRecursiveStringXrefs extends GhidraScript {
    private void collect(Address address, int depth, HashSet<Address> visited,
                         LinkedHashSet<Function> functions) {
        if (!visited.add(address) || depth < 0) {
            return;
        }
        for (Reference reference : getReferencesTo(address)) {
            Address from = reference.getFromAddress();
            Function function = getFunctionContaining(from);
            if (function != null) {
                functions.add(function);
            } else if (depth > 0) {
                println("DATA_XREF " + from + " -> " + address);
                collect(from, depth - 1, visited, functions);
            }
        }
    }

    @Override
    public void run() throws Exception {
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        HashSet<Address> visited = new HashSet<>();
        LinkedHashSet<Function> functions = new LinkedHashSet<>();
        for (String target : getScriptArgs()) {
            byte[] needle = target.getBytes(StandardCharsets.US_ASCII);
            for (MemoryBlock block : currentProgram.getMemory().getBlocks()) {
                if (!block.isInitialized() || block.getSize() > Integer.MAX_VALUE) continue;
                byte[] bytes = new byte[(int) block.getSize()];
                block.getBytes(block.getStart(), bytes);
                for (int offset = 0; offset <= bytes.length - needle.length; offset++) {
                    int index = 0;
                    while (index < needle.length && bytes[offset + index] == needle[index]) index++;
                    if (index == needle.length) {
                        Address address = block.getStart().add(offset);
                        println("TARGET " + target + " at " + address);
                        collect(address, 3, visited, functions);
                    }
                }
            }
        }
        for (Function function : functions) {
            println("FUNCTION " + function.getName() + " at " + function.getEntryPoint());
            DecompileResults result = decompiler.decompileFunction(function, 300, monitor);
            if (result.decompileCompleted()) println(result.getDecompiledFunction().getC());
        }
        decompiler.dispose();
    }
}
