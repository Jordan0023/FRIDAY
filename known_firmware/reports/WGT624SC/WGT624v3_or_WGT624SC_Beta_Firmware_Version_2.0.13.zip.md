# Firmware Audit: WGT624SC / WGT624v3_or_WGT624SC_Beta_Firmware_Version_2.0.13.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGT624V3/WGT624v3%20or%20WGT624SC%20Beta%20Firmware%20Version%202.0.13.zip
- Local path: known_firmware/firmware/WGT624SC/WGT624v3_or_WGT624SC_Beta_Firmware_Version_2.0.13.zip
- SHA-256: `6a8cdfe2bd7c12ad4d7352bfc3311b2a452794d604b8efe304fa84b5004805db`
- Size: 1084224 bytes
- Version: 0.13
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6a8cdfe2bd7c12ad exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
