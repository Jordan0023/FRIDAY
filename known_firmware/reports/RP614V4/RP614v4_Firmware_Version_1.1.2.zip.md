# Firmware Audit: RP614V4 / RP614v4_Firmware_Version_1.1.2.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RP614v4/RP614v4%20Firmware%20Version%201.1.2.zip
- Local path: known_firmware/firmware/RP614V4/RP614v4_Firmware_Version_1.1.2.zip
- SHA-256: `437e493e4b112b5a0efe255c49ffe9f025342f5c4e4fbf5bd7bf277afe7a4cee`
- Size: 1579777 bytes
- Version: 1.2
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/437e493e4b112b5a exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
