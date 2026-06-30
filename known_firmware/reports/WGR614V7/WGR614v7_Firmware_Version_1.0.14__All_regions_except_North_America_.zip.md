# Firmware Audit: WGR614V7 / WGR614v7_Firmware_Version_1.0.14__All_regions_except_North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGR614V7/WGR614v7%20Firmware%20Version%201.0.14%20(All%20regions%20except%20North%20America).zip
- Local path: known_firmware/firmware/WGR614V7/WGR614v7_Firmware_Version_1.0.14__All_regions_except_North_America_.zip
- SHA-256: `b1ad716b958b91bc973421bc646452200bae86ffda3ba3b214c50d9d7e25671b`
- Size: 956328 bytes
- Version: 0.14__All_regions_except_North_America_
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `sSHd`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b1ad716b958b91bc exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
