# Firmware Audit: WGR614V2 / WGR614v2_and_WGR614v3_Firmware_Version_2.16.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGR614V3/WGR614v2%20and%20WGR614v3%20Firmware%20Version%202.16.zip
- Local path: known_firmware/firmware/WGR614V2/WGR614v2_and_WGR614v3_Firmware_Version_2.16.zip
- SHA-256: `5d4b78d35fe37b8f9ae696c1f7f077d5480e6502b7ba97adb396a2f4f04ce772`
- Size: 1012804 bytes
- Version: unknown
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5d4b78d35fe37b8f exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
