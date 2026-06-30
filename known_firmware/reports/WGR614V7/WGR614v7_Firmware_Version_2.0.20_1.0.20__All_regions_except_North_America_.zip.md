# Firmware Audit: WGR614V7 / WGR614v7_Firmware_Version_2.0.20_1.0.20__All_regions_except_North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGR614V7/WGR614v7%20Firmware%20Version%202.0.20_1.0.20%20(All%20regions%20except%20North%20America).zip
- Local path: known_firmware/firmware/WGR614V7/WGR614v7_Firmware_Version_2.0.20_1.0.20__All_regions_except_North_America_.zip
- SHA-256: `5240235310ba412e47b643fa41303545d323b48645c756f54784b7813ba7c83b`
- Size: 960658 bytes
- Version: 0.20_1.0.20__All_regions_except_North_America_
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5240235310ba412e exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
