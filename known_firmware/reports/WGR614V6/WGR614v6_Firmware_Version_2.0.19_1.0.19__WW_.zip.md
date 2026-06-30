# Firmware Audit: WGR614V6 / WGR614v6_Firmware_Version_2.0.19_1.0.19__WW_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGR614V6/WGR614v6%20Firmware%20Version%202.0.19_1.0.19%20(WW).zip
- Local path: known_firmware/firmware/WGR614V6/WGR614v6_Firmware_Version_2.0.19_1.0.19__WW_.zip
- SHA-256: `ac903ef1a9fb3eb05a02b155476a58a1b7b5d733003eec8b271be32f35df5a5b`
- Size: 830388 bytes
- Version: 0.19_1.0.19__WW_
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ac903ef1a9fb3eb0 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
