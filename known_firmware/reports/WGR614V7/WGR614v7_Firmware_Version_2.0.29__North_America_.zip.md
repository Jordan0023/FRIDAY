# Firmware Audit: WGR614V7 / WGR614v7_Firmware_Version_2.0.29__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGR614V7/WGR614v7%20Firmware%20Version%202.0.29%20(North%20America).zip
- Local path: known_firmware/firmware/WGR614V7/WGR614v7_Firmware_Version_2.0.29__North_America_.zip
- SHA-256: `923d57ee5ebb52ae857eb4c9fa5c032a6794051841f2524a205e5253b74b3be7`
- Size: 962181 bytes
- Version: 0.29__North_America_
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/923d57ee5ebb52ae exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
