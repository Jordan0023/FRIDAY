import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;
import java.nio.charset.StandardCharsets;

public class DumpNvramDefaults extends GhidraScript {
    private String readCString(Address address) throws Exception {
        if (address == null || !currentProgram.getMemory().contains(address)) {
            return null;
        }
        byte[] bytes = new byte[4096];
        int length = 0;
        while (length < bytes.length) {
            byte value = currentProgram.getMemory().getByte(address.add(length));
            if (value == 0) {
                return new String(bytes, 0, length, StandardCharsets.UTF_8);
            }
            bytes[length++] = value;
        }
        return null;
    }

    @Override
    public void run() throws Exception {
        Memory memory = currentProgram.getMemory();
        int pointerSize = currentProgram.getDefaultPointerSize();
        for (String tableName : getScriptArgs()) {
            SymbolIterator symbols =
                currentProgram.getSymbolTable().getSymbols(tableName);
            Symbol symbol = symbols.hasNext() ? symbols.next() : null;
            if (symbol == null) {
                println("NOT_FOUND " + tableName);
                continue;
            }
            Address entry = symbol.getAddress();
            println("TABLE " + tableName + " at " + entry);
            for (int index = 0; index < 8192; index++) {
                long nameOffset = memory.getInt(entry) & 0xffffffffL;
                long valueOffset = memory.getInt(entry.add(pointerSize)) & 0xffffffffL;
                if (nameOffset == 0) {
                    println("END index=" + index);
                    break;
                }
                Address nameAddress = currentProgram.getAddressFactory()
                    .getDefaultAddressSpace().getAddress(nameOffset);
                Address valueAddress = currentProgram.getAddressFactory()
                    .getDefaultAddressSpace().getAddress(valueOffset);
                String name = readCString(nameAddress);
                String value = valueOffset == 0 ? "" : readCString(valueAddress);
                println(index + "\t" + name + "\t" + value);
                // ASUSWRT's current nvram_tuple has two pointers and three
                // 32-bit metadata fields.
                entry = entry.add(pointerSize * 5L);
            }
        }
    }
}
