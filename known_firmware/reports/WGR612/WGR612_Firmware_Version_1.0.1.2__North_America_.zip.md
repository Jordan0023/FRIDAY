# Firmware Audit: WGR612 / WGR612_Firmware_Version_1.0.1.2__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGR612/WGR612%20Firmware%20Version%201.0.1.2%20(North%20America).zip
- Local path: known_firmware/firmware/WGR612/WGR612_Firmware_Version_1.0.1.2__North_America_.zip
- SHA-256: `7dd39c487ab5eac0affbd8ddd1e0099a19060204db9437166ecbffe4daf47b1e`
- Size: 1817392 bytes
- Version: 0.1.2__North_America_
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7dd39c487ab5eac0 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
