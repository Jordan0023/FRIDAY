# Firmware Audit: RP614V1 / RP614-Firmware-Version-4.15.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RP614v1/RP614-Firmware-Version-4.15.zip
- Local path: known_firmware/firmware/RP614V1/RP614-Firmware-Version-4.15.zip
- SHA-256: `c9cce60206a2920116bbccc175954a1a5737544c82f94e0a0bc3f7d3e538ac06`
- Size: 603802 bytes
- Version: 4.15
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `cgi-bin, httpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `Eval, SYSTEM, System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c9cce60206a29201 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
