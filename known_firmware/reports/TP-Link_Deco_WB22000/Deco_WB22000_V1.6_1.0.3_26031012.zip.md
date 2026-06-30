# Firmware Audit: TP-Link Deco WB22000 / Deco_WB22000_V1.6_1.0.3_26031012.zip

- Source URL: https://static.tp-link.com/upload/firmware/2026/202604/20260415/Deco WB22000_V1.6_1.0.3_26031012.zip
- Local path: known_firmware/firmware/TP-Link_Deco_WB22000/Deco_WB22000_V1.6_1.0.3_26031012.zip
- SHA-256: `cc8721dc91082180e9a19cc7fa38b2e83ba7f670c26159efe0b90a28e1503cc6`
- Size: 51403106 bytes
- Version: V1.6_1.0.3 Build 26031012
- Release date: 2026-04-15

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA, bOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/cc8721dc91082180 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
