// Resolve pointer-sized data entries in an address range to printable strings.
import java.io.File;
import java.io.FileWriter;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.listing.Function;

public class FridayPointerStringRange extends GhidraScript {
    @Override public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 3) {
            throw new IllegalArgumentException("output start end required");
        }
        Address start = toAddr(args[1]);
        Address end = toAddr(args[2]);
        Memory memory = currentProgram.getMemory();
        try (FileWriter writer = new FileWriter(new File(args[0]), false)) {
            for (Address at = start; at.compareTo(end) <= 0; at = at.add(4)) {
                long raw;
                try {
                    raw = Integer.toUnsignedLong(memory.getInt(at));
                } catch (Exception e) {
                    continue;
                }
                Address target = toAddr(raw);
                String value = readAscii(memory, target, 512);
                if (value != null) {
                    writer.write(at + " -> " + target + " = " + value + "\n");
                    continue;
                }
                Function function = getFunctionAt(target);
                if (function != null) {
                    writer.write(at + " -> " + target + " = FUNCTION " +
                        function.getName() + "\n");
                } else {
                    writer.write(at + " -> " + target + "\n");
                }
            }
        }
    }

    private String readAscii(Memory memory, Address at, int limit) {
        StringBuilder value = new StringBuilder();
        try {
            for (int i = 0; i < limit; i++) {
                int b = memory.getByte(at.add(i)) & 0xff;
                if (b == 0) return value.length() >= 2 ? value.toString() : null;
                if (b < 0x20 || b > 0x7e) return null;
                value.append((char)b);
            }
        } catch (Exception e) {
            return null;
        }
        return null;
    }
}
