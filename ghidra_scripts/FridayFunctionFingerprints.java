// Export compact function fingerprints for cross-version patch analysis.

import java.io.File;
import java.io.FileWriter;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.util.LinkedHashSet;
import java.util.Set;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.mem.MemoryAccessException;
import ghidra.program.model.symbol.Reference;

public class FridayFunctionFingerprints extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 1) {
            throw new IllegalArgumentException("output JSONL path required");
        }
        File output = new File(args[0]);
        if (output.getParentFile() != null) output.getParentFile().mkdirs();
        try (FileWriter writer = new FileWriter(output, false)) {
            FunctionIterator functions = currentProgram.getFunctionManager().getFunctions(true);
            for (Function function : functions) {
                if (monitor.isCancelled()) break;
                if (function.isExternal() || function.isThunk()) continue;
                StringBuilder mnemonicShape = new StringBuilder();
                Set<String> callees = new LinkedHashSet<>();
                Set<String> strings = new LinkedHashSet<>();
                InstructionIterator instructions =
                    currentProgram.getListing().getInstructions(function.getBody(), true);
                long instructionCount = 0;
                while (instructions.hasNext()) {
                    Instruction instruction = instructions.next();
                    instructionCount++;
                    mnemonicShape.append(instruction.getMnemonicString()).append(';');
                    for (Reference reference : instruction.getReferencesFrom()) {
                        Address target = reference.getToAddress();
                        Function callee = currentProgram.getFunctionManager()
                            .getFunctionAt(target);
                        if (callee != null) callees.add(callee.getName());
                        collectString(target, strings);
                    }
                }
                writer.write("{\"address\":\"" + function.getEntryPoint()
                    + "\",\"name\":\"" + json(function.getName())
                    + "\",\"bytes\":" + function.getBody().getNumAddresses()
                    + ",\"instructions\":" + instructionCount
                    + ",\"mnemonic_sha256\":\"" + sha256(mnemonicShape.toString())
                    + "\",\"callees\":" + jsonArray(callees)
                    + ",\"strings\":" + jsonArray(strings) + "}\n");
            }
        }
    }

    private void collectString(Address address, Set<String> strings)
            throws MemoryAccessException {
        Data data = currentProgram.getListing().getDataAt(address);
        if (data == null || !data.hasStringValue()) return;
        Object value = data.getValue();
        if (value == null) return;
        String text = value.toString();
        if (text.length() >= 3 && text.length() <= 240 && strings.size() < 80) {
            strings.add(text);
        }
    }

    private static String sha256(String value) throws Exception {
        byte[] digest = MessageDigest.getInstance("SHA-256")
            .digest(value.getBytes(StandardCharsets.UTF_8));
        StringBuilder result = new StringBuilder();
        for (byte item : digest) result.append(String.format("%02x", item & 0xff));
        return result.toString();
    }

    private static String jsonArray(Set<String> values) {
        StringBuilder result = new StringBuilder("[");
        boolean first = true;
        for (String value : values) {
            if (!first) result.append(',');
            result.append('"').append(json(value)).append('"');
            first = false;
        }
        return result.append(']').toString();
    }

    private static String json(String value) {
        return value.replace("\\", "\\\\").replace("\"", "\\\"")
            .replace("\n", "\\n").replace("\r", "\\r").replace("\t", "\\t");
    }
}
