// Decompile functions that directly reference caller-supplied string fragments.

import java.io.File;
import java.io.FileWriter;
import java.util.LinkedHashSet;
import java.util.Set;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Reference;

public class FridayStringXrefs extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 2) {
            throw new IllegalArgumentException(
                "output path and at least one string fragment required"
            );
        }
        File output = new File(args[0]);
        if (output.getParentFile() != null) output.getParentFile().mkdirs();
        Set<Function> owners = new LinkedHashSet<>();
        Listing listing = currentProgram.getListing();

        try (FileWriter writer = new FileWriter(output, false)) {
            for (MemoryBlock block : currentProgram.getMemory().getBlocks()) {
                if (!block.isInitialized()) continue;
                Data data = listing.getDefinedDataAt(block.getStart());
                Address cursor = block.getStart();
                while (cursor.compareTo(block.getEnd()) <= 0) {
                    data = listing.getDefinedDataAt(cursor);
                    if (data != null) {
                        Object rawValue = data.getValue();
                        String value =
                            rawValue instanceof String ? (String) rawValue : null;
                        if (value != null && matches(value, args)) {
                            writer.write(
                                "STRING " + data.getAddress() + " " + value + "\n"
                            );
                            for (Reference reference :
                                    currentProgram.getReferenceManager()
                                        .getReferencesTo(data.getAddress())) {
                                Function owner = currentProgram.getFunctionManager()
                                    .getFunctionContaining(reference.getFromAddress());
                                if (owner != null) owners.add(owner);
                                writer.write(
                                    "REF " + reference.getFromAddress() + " owner="
                                        + (owner == null ? "NONE" : owner.getName()) + "\n"
                                );
                            }
                        }
                        cursor = data.getMaxAddress().next();
                    } else {
                        cursor = cursor.next();
                    }
                    if (cursor == null) break;
                }
            }

            DecompInterface decompiler = new DecompInterface();
            decompiler.openProgram(currentProgram);
            try {
                Set<Function> callers = new LinkedHashSet<>();
                for (Function owner : owners) {
                    for (Reference reference :
                            currentProgram.getReferenceManager()
                                .getReferencesTo(owner.getEntryPoint())) {
                        Function caller = currentProgram.getFunctionManager()
                            .getFunctionContaining(reference.getFromAddress());
                        if (caller != null) callers.add(caller);
                        writer.write(
                            "CALLER_REF target=" + owner.getName() + " from="
                                + reference.getFromAddress() + " owner="
                                + (caller == null ? "NONE" : caller.getName()) + "\n"
                        );
                    }
                }
                owners.addAll(callers);
                for (Function owner : owners) {
                    DecompileResults result =
                        decompiler.decompileFunction(owner, 120, monitor);
                    writer.write(
                        "\n===== " + owner.getName() + " @ "
                            + owner.getEntryPoint() + " =====\n"
                    );
                    if (result.decompileCompleted()
                            && result.getDecompiledFunction() != null) {
                        writer.write(result.getDecompiledFunction().getC());
                    } else {
                        writer.write("DECOMPILE_FAILED\n");
                    }
                    writer.write("\n");
                }
            } finally {
                decompiler.dispose();
            }
        }
    }

    private static boolean matches(String value, String[] args) {
        for (int index = 1; index < args.length; index++) {
            if (value.contains(args[index])) return true;
        }
        return false;
    }
}
