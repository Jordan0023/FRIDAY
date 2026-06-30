# Firmware Audit: TP-Link Deco X55 / Deco_X55_V1_1.8.0_Build_25102213_Rel._43970.zip

- Source URL: https://static.tp-link.com/upload/firmware/2026/202601/20260116/Deco_X55_V1_1.8.0_Build_25102213_Rel._43970.zip
- Local path: known_firmware/firmware/TP-Link_Deco_X55/Deco_X55_V1_1.8.0_Build_25102213_Rel._43970.zip
- SHA-256: `a7c0d1aec8d9a56d9eed37fbf01d7d4471166252ad9763b698563fcb6e77ac02`
- Size: 38108416 bytes
- Version: V1.6_1.8.0 Build 25102213
- Release date: 2026-01-16

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a7c0d1aec8d9a56d exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
