# Firmware Audit: WGR614V7 / WGR614v7_Firmware_Version_1.0.14__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGR614V7/WGR614v7%20Firmware%20Version%201.0.14%20(North%20America).zip
- Local path: known_firmware/firmware/WGR614V7/WGR614v7_Firmware_Version_1.0.14__North_America_.zip
- SHA-256: `a562ec1589abfbd72a1ebf077096682bed57513bb440d3dfa919ef49d8ec1680`
- Size: 956415 bytes
- Version: 0.14__North_America_
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a562ec1589abfbd7 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
