# Firmware Audit: TP-Link Deco BE77 / Deco_BE77_V1_1.3.0_260508.zip

- Source URL: https://static.tp-link.com/upload/firmware/2026/202606/20260602/Deco BE77_V1_1.3.0_260508.zip
- Local path: known_firmware/firmware/TP-Link_Deco_BE77/Deco_BE77_V1_1.3.0_260508.zip
- SHA-256: `0988cd3d464d18c807889ca73b7e0927617503ef56f4fa36f7a0b7282a55a702`
- Size: 49961146 bytes
- Version: V1.6_1.3.0 Build 20260508
- Release date: 2026-06-02

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

- binwalk -eM --directory known_firmware/extracted/0988cd3d464d18c8 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
