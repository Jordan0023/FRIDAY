# Firmware Audit: WNR1000V1 / WNR1000_Firmware_Version_1.0.1.15__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR1000V1/WNR1000%20Firmware%20Version%201.0.1.15%20(North%20America).zip
- Local path: known_firmware/firmware/WNR1000V1/WNR1000_Firmware_Version_1.0.1.15__North_America_.zip
- SHA-256: `a35d6f506749d24d92a4f7554cec137235525453ab8469d6951dd287b6febfce`
- Size: 2502768 bytes
- Version: 0.1.15__North_America_
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

Evidence: `gets, sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a35d6f506749d24d exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
