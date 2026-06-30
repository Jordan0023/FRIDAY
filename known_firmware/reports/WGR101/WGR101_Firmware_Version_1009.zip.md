# Firmware Audit: WGR101 / WGR101_Firmware_Version_1009.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGR101/WGR101%20Firmware%20Version%201009.zip
- Local path: known_firmware/firmware/WGR101/WGR101_Firmware_Version_1009.zip
- SHA-256: `db4885ce1181bcd54cb75fdf040e4d8ebcf0564aa4345c6be2a245908f9510b9`
- Size: 705188 bytes
- Version: unknown
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/db4885ce1181bcd5 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
