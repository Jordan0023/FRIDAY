# Firmware Audit: RP614V3 / RP614v3_Firmware_Version_6.0.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RP614v3/RP614v3%20Firmware%20Version%206.0.zip
- Local path: known_firmware/firmware/RP614V3/RP614v3_Firmware_Version_6.0.zip
- SHA-256: `09837782b5f32e95cb5a86dadce02aa6374223093cf525a8adbbe4fd83fd6393`
- Size: 734986 bytes
- Version: unknown
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

- binwalk -eM --directory known_firmware/extracted/09837782b5f32e95 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
