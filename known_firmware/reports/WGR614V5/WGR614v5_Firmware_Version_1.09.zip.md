# Firmware Audit: WGR614V5 / WGR614v5_Firmware_Version_1.09.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGR614V5/WGR614v5%20Firmware%20Version%201.09.zip
- Local path: known_firmware/firmware/WGR614V5/WGR614v5_Firmware_Version_1.09.zip
- SHA-256: `86ed47ebe9ac9265943ca3462f0ae515965ea6f76a5d2af63d53b5fed19007a9`
- Size: 891107 bytes
- Version: unknown
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/86ed47ebe9ac9265 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
