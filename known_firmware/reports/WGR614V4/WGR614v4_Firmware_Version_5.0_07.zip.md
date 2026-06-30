# Firmware Audit: WGR614V4 / WGR614v4_Firmware_Version_5.0_07.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGR614V4/WGR614v4%20Firmware%20Version%205.0_07.zip
- Local path: known_firmware/firmware/WGR614V4/WGR614v4_Firmware_Version_5.0_07.zip
- SHA-256: `e2e0bfee19705bdda2c4e6678dff2dabcdad45f6b1930f7f1a98fa52f1cb34f4`
- Size: 764174 bytes
- Version: unknown
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e2e0bfee19705bdd exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
