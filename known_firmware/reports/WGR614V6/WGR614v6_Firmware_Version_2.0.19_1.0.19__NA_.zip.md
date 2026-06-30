# Firmware Audit: WGR614V6 / WGR614v6_Firmware_Version_2.0.19_1.0.19__NA_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGR614V6/WGR614v6%20Firmware%20Version%202.0.19_1.0.19%20(NA).zip
- Local path: known_firmware/firmware/WGR614V6/WGR614v6_Firmware_Version_2.0.19_1.0.19__NA_.zip
- SHA-256: `a8414968d558b60026e73f45b664e797d0ffd724bbc9afee35c73b7b06a88faf`
- Size: 830651 bytes
- Version: 0.19_1.0.19__NA_
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a8414968d558b600 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
