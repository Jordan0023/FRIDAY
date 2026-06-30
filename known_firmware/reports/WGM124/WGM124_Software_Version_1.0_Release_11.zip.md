# Firmware Audit: WGM124 / WGM124_Software_Version_1.0_Release_11.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGM124/WGM124%20Software%20Version%201.0%20Release%2011.zip
- Local path: known_firmware/firmware/WGM124/WGM124_Software_Version_1.0_Release_11.zip
- SHA-256: `4d08efefaf69948f52fe3143d44e7e0b4ac0b9fc5699cc5855b4db2581d3f803`
- Size: 2870676 bytes
- Version: unknown
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4d08efefaf69948f exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
