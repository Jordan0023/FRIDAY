// Follow references to an address through data tables and decompile code users.
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.Set;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;

public class FridayRecursiveAddressAudit extends GhidraScript {
    @Override public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) throw new IllegalArgumentException("output and addresses required");
        File output = new File(args[0]);
        if (output.getParentFile() != null) output.getParentFile().mkdirs();
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);
        try (FileWriter writer = new FileWriter(output, false)) {
            for (int i = 1; i < args.length; i++) {
                Address target = toAddr(args[i]);
                Set<Function> functions = new LinkedHashSet<>();
                Set<Address> visited = new HashSet<>();
                ArrayDeque<AddressDepth> queue = new ArrayDeque<>();
                queue.add(new AddressDepth(target, 0));
                writer.write("\n===== TARGET " + target + " =====\n");
                while (!queue.isEmpty()) {
                    AddressDepth item = queue.removeFirst();
                    if (!visited.add(item.address) || item.depth > 4) continue;
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

    private static class AddressDepth {
        final Address address;
        final int depth;
        AddressDepth(Address address, int depth) {
            this.address = address;
            this.depth = depth;
        }
    }
}
