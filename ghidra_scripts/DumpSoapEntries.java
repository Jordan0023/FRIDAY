import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.Memory;
import ghidra.program.model.mem.MemoryBlock;

public class DumpSoapEntries extends GhidraScript {
    private String readCString(Address address) {
        if (address == null || !currentProgram.getMemory().contains(address)) {
            return null;
        }
        StringBuilder out = new StringBuilder();
        try {
            for (int i = 0; i < 256; i++) {
                int b = currentProgram.getMemory().getByte(address.add(i)) & 0xff;
                if (b == 0) return out.toString();
                if (b < 0x20 || b > 0x7e) return null;
                out.append((char)b);
            }
        } catch (Exception ignored) {
            return null;
        }
        return null;
    }

    private long u32(Address address) throws Exception {
        return currentProgram.getMemory().getInt(address) & 0xffffffffL;
    }

    @Override
    public void run() throws Exception {
        if (getScriptArgs().length < 2) {
            printerr("usage: DumpSoapEntries.java OUTPUT ACTION...");
            return;
        }
        PrintWriter out = new PrintWriter(new FileWriter(getScriptArgs()[0]));
        Memory memory = currentProgram.getMemory();
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);

        for (int arg = 1; arg < getScriptArgs().length; arg++) {
            String needle = getScriptArgs()[arg];
            if (needle.equals("ALL")) {
                Address entry = toAddr(0x001d7804L);
                for (int index = 0; index < 256; index++, entry = entry.add(16)) {
                    long service = u32(entry);
                    long action = u32(entry.add(4));
                    long handler = u32(entry.add(8));
                    long flags = u32(entry.add(12));
                    String serviceS = readCString(toAddr(service));
                    String actionS = readCString(toAddr(action));
                    if (serviceS == null || actionS == null || !memory.contains(toAddr(handler))) {
                        break;
                    }
                    out.printf(
                        "INDEX=%d entry=%s service=%s action=%s handler=%08x flags=%08x unauth=%s%n",
                        index, entry, serviceS, actionS, handler, flags,
                        ((flags & 2) != 0) ? "yes" : "no");
                }
                continue;
            }
            List<Address> strings = new ArrayList<>();
            for (MemoryBlock block : memory.getBlocks()) {
                if (!block.isInitialized()) continue;
                Address hit = block.getStart();
                while (hit != null && hit.compareTo(block.getEnd()) <= 0) {
                    hit = memory.findBytes(
                        hit, block.getEnd(), needle.getBytes("US-ASCII"), null, true, monitor);
                    if (hit != null) {
                        strings.add(hit);
                        hit = hit.add(1);
                    }
                }
            }
            out.println("=== " + needle + " strings=" + strings + " ===");
            for (Address stringAddress : strings) {
                long target = stringAddress.getOffset() & 0xffffffffL;
                for (MemoryBlock block : memory.getBlocks()) {
                    if (!block.isInitialized()) continue;
                    Address p = block.getStart();
                    long align = p.getOffset() & 3;
                    if (align != 0) p = p.add(4 - align);
                    while (p.compareTo(block.getEnd()) <= 0 && p.add(3).compareTo(block.getEnd()) <= 0) {
                        long value;
                        try {
                            value = u32(p);
                        } catch (Exception e) {
                            break;
                        }
                        if (value == target) {
                            for (int delta : new int[] {0, -4}) {
                                Address entry;
                                try {
                                    entry = p.add(delta);
                                    long first = u32(entry);
                                    long second = u32(entry.add(4));
                                    long handler = u32(entry.add(8));
                                    long flags = u32(entry.add(12));
                                    Address firstA = toAddr(first);
                                    Address secondA = toAddr(second);
                                    String firstS = readCString(firstA);
                                    String secondS = readCString(secondA);
                                    out.printf(
                                        "pointer=%s candidate=%s first=%08x %s second=%08x %s handler=%08x flags=%08x%n",
                                        p, entry, first, firstS, second, secondS, handler, flags);
                                    Function f = getFunctionAt(toAddr(handler));
                                    if (f == null) f = getFunctionContaining(toAddr(handler));
                                    if (f == null && memory.contains(toAddr(handler))) {
                                        disassemble(toAddr(handler));
                                        createFunction(toAddr(handler), null);
                                        f = getFunctionAt(toAddr(handler));
                                    }
                                    if (f != null) {
                                        out.println("FUNCTION " + f.getName() + " @ " + f.getEntryPoint());
                                        DecompileResults result = decompiler.decompileFunction(f, 60, monitor);
                                        if (result.decompileCompleted()) {
                                            out.println(result.getDecompiledFunction().getC());
                                        } else {
                                            out.println("DECOMPILE FAILED: " + result.getErrorMessage());
                                        }
                                    }
                                } catch (Exception ignored) {
                                }
                            }
                        }
                        p = p.add(4);
                    }
                }
            }
        }
        out.close();
        decompiler.dispose();
    }
}
