# Firmware Audit: WGT624V1 / WGT624v1_and_WGT624v2_Firmware_Version_4.2.11.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGT624V2/WGT624v1%20and%20WGT624v2%20Firmware%20Version%204.2.11.zip
- Local path: known_firmware/firmware/WGT624V1/WGT624v1_and_WGT624v2_Firmware_Version_4.2.11.zip
- SHA-256: `5310f5f9eda629a9df240f3b9a42c4a8cfc402230e6a5834dee41356e23648c1`
- Size: 1203670 bytes
- Version: 2.11
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5310f5f9eda629a9 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
