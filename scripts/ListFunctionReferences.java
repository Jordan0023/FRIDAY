import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;

public class ListFunctionReferences extends GhidraScript {
    @Override
    public void run() throws Exception {
        for (String value : getScriptArgs()) {
            Address address = toAddr(value);
            Function target = getFunctionContaining(address);
            if (target == null) {
                println("NO_FUNCTION " + value);
                continue;
            }
            println("===== REFERENCES TO " + target.getName(true) + " @ "
                    + target.getEntryPoint() + " =====");
            ReferenceIterator refs =
                    currentProgram.getReferenceManager().getReferencesTo(target.getEntryPoint());
            while (refs.hasNext()) {
                Reference ref = refs.next();
                Function caller =
                        currentProgram.getFunctionManager().getFunctionContaining(ref.getFromAddress());
                println(ref.getFromAddress() + " " + ref.getReferenceType()
                        + " caller=" + (caller == null ? "<none>" : caller.getName(true)));
            }
        }
    }
}
