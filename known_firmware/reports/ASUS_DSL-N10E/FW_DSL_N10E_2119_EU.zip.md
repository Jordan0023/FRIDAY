# Firmware Audit: ASUS DSL-N10E / FW_DSL_N10E_2119_EU.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N10E/FW_DSL_N10E_2119_EU.zip
- Local path: known_firmware/firmware/ASUS_DSL-N10E/FW_DSL_N10E_2119_EU.zip
- SHA-256: `9e7e9a7a6eccb97fd40255c4a5357876f8c1e6508ce81226a0daeffaf0d5ae81`
- Size: 2801236 bytes
- Version: 2.1.19_EU
- Release date: 2013/04/09

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9e7e9a7a6eccb97f exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
