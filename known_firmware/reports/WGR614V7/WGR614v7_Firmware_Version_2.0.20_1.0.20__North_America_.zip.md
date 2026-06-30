# Firmware Audit: WGR614V7 / WGR614v7_Firmware_Version_2.0.20_1.0.20__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGR614V7/WGR614v7%20Firmware%20Version%202.0.20_1.0.20%20(North%20America).zip
- Local path: known_firmware/firmware/WGR614V7/WGR614v7_Firmware_Version_2.0.20_1.0.20__North_America_.zip
- SHA-256: `dd617d0842950e80219cfc59a524e23eb6ca0e3da302ba5a0e012458bd37cd27`
- Size: 960418 bytes
- Version: 0.20_1.0.20__North_America_
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/dd617d0842950e80 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
