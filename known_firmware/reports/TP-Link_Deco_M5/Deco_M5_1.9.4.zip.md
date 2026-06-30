# Firmware Audit: TP-Link Deco M5 / Deco_M5_1.9.4.zip

- Source URL: https://static.tp-link.com/upload/firmware/2026/202604/20260414/Deco_M5_1.9.4.zip
- Local path: known_firmware/firmware/TP-Link_Deco_M5/Deco_M5_1.9.4.zip
- SHA-256: `771b1071da31961cc62e7116ac80c4d062a5c299f056d187f399468a5b41b9b3`
- Size: 17585953 bytes
- Version: V3.8_1.9.4 Build 20260312
- Release date: 2026-04-14

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa, bOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/771b1071da31961c exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
