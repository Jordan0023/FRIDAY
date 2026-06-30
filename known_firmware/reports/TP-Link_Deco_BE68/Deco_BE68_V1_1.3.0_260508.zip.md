# Firmware Audit: TP-Link Deco BE68 / Deco_BE68_V1_1.3.0_260508.zip

- Source URL: https://static.tp-link.com/upload/firmware/2026/202605/20260527/Deco BE68_V1_1.3.0_260508.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE68/Deco_BE68_V1_1.3.0_260508.zip
- SHA-256: `388183fd8716d6b04981d11bf459f5091ee3f7e91aa8b3133b3b355ffd92b30a`
- Size: 49961146 bytes
- Version: V1.6_1.3.0 Build 20260508
- Release date: 2026-05-27

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PWd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, Boa, bOA, bOa, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/388183fd8716d6b0 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
