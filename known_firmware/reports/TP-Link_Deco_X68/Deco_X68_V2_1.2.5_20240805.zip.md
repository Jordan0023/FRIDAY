# Firmware Audit: TP-Link Deco X68 / Deco_X68_V2_1.2.5_20240805.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202408/20240823/Deco_X68_V2_1.2.5_20240805.zip
- Local path: known_firmware/firmware/TP-Link_Deco_X68/Deco_X68_V2_1.2.5_20240805.zip
- SHA-256: `69ed59fcf8d3fe159067798b9e774207cf279324d4794fb9ae84cc6753976cc5`
- Size: 27348348 bytes
- Version: V2.6_1.2.5 Build 20240805
- Release date: 2024-08-23

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PwD`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/69ed59fcf8d3fe15 stopped: extraction exceeded 2048 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
