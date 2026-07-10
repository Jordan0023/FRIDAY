from ghidra.app.decompiler import DecompInterface
from ghidra.program.model.address import AddressSet

targets = [
    "RMT_invite.cgi",
    "RMT_invite",
    "device_name2",
    "genieping.cgi",
    "genieping2.cgi",
    "rccommand.cgi",
    "rccommand_test.cgi",
    "newdebug.cgi",
    "openvpn_hidden.cgi",
    "readycloud_control.cgi",
    "targetTimezone",
    "burn_sw_feature 2>/tmp/sw_feature.txt",
]

fm = currentProgram.getFunctionManager()
refs = currentProgram.getReferenceManager()
listing = currentProgram.getListing()

ifc = DecompInterface()
ifc.openProgram(currentProgram)

seen = set()

def get_string_at(addr):
    data = listing.getDataAt(addr)
    if data is None:
        return None
    try:
        return str(data.getValue())
    except:
        return None

for s in targets:
    print("\\n===== TARGET %s =====" % s)
    found = []
    mem = currentProgram.getMemory()
    for block in mem.getBlocks():
        if not block.isInitialized():
            continue
        start = block.getStart()
        data = bytearray()
        try:
            data = bytearray(block.getSize())
            block.getBytes(start, data)
        except:
            continue
        needle = s.encode("ascii")
        idx = data.find(needle)
        while idx != -1:
            addr = start.add(idx)
            found.append(addr)
            idx = data.find(needle, idx + 1)
    for addr in found:
        print("STRING %s at %s" % (s, addr))
        for ref in refs.getReferencesTo(addr):
            f = fm.getFunctionContaining(ref.getFromAddress())
            print("  REF from %s func=%s" % (ref.getFromAddress(), f.getName() if f else None))
            if f is not None and f.getEntryPoint().toString() not in seen:
                seen.add(f.getEntryPoint().toString())
                res = ifc.decompileFunction(f, 60, monitor)
                print("----- FUNC %s %s -----" % (f.getName(), f.getEntryPoint()))
                if res and res.decompileCompleted():
                    print(res.getDecompiledFunction().getC())
                else:
                    print("DECOMPILE_FAILED")
