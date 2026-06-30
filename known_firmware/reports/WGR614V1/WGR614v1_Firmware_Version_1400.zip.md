# Firmware Audit: WGR614V1 / WGR614v1_Firmware_Version_1400.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGR614V1/WGR614v1%20Firmware%20Version%201400.zip
- Local path: known_firmware/firmware/WGR614V1/WGR614v1_Firmware_Version_1400.zip
- SHA-256: `ab8aca9e8a98e951ae1f81f670421c33024dc947b69a0df62bea73a4d84b8e21`
- Size: 653485 bytes
- Version: unknown
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ab8aca9e8a98e951 exited 0: WARNING: Extractor.execute failed to run external extractor 'jar xvf '%e'': [Errno 2] No such file or directory: 'jar', 'jar xvf '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
