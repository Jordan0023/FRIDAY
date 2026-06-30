# Firmware Audit: WGR612 / WGR612_Firmware_Version_1.0.1.2__Latin_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGR612/WGR612%20Firmware%20Version%201.0.1.2%20(Latin%20America).zip
- Local path: known_firmware/firmware/WGR612/WGR612_Firmware_Version_1.0.1.2__Latin_America_.zip
- SHA-256: `4ee38f17fd00f86051258814ccee7fb803893c27bdb030c0a67b5b6697c9dc47`
- Size: 1819474 bytes
- Version: 0.1.2__Latin_America_
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

- binwalk -eM --directory known_firmware/extracted/4ee38f17fd00f860 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
