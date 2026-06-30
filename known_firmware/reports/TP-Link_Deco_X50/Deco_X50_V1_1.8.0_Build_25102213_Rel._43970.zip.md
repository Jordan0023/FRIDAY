# Firmware Audit: TP-Link Deco X50 / Deco_X50_V1_1.8.0_Build_25102213_Rel._43970.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202512/20251208/Deco_X50_V1_1.8.0_Build_25102213_Rel._43970.zip
- Local path: known_firmware/firmware/TP-Link_Deco_X50/Deco_X50_V1_1.8.0_Build_25102213_Rel._43970.zip
- SHA-256: `f5891e871865d6213b1a6b05aa4d65051e19a0a37bee0b6550d9033fb4092a12`
- Size: 38142778 bytes
- Version: V1.6_1.8.0 Build 25102213
- Release date: 2025-12-08

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f5891e871865d621 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
