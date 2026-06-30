# Firmware Audit: RP614V2 / RP614v2_Firmware_Version_5.20.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RP614v2/RP614v2%20Firmware%20Version%205.20.zip
- Local path: known_firmware/firmware/RP614V2/RP614v2_Firmware_Version_5.20.zip
- SHA-256: `60e59480f42bd10a62373d4e3784a00cadc6b565018f386f9554926fd83ec17a`
- Size: 685421 bytes
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

- binwalk -eM --directory known_firmware/extracted/60e59480f42bd10a exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
