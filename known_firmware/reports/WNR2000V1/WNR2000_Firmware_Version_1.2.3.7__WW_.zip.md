# Firmware Audit: WNR2000V1 / WNR2000_Firmware_Version_1.2.3.7__WW_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR2000V1/WNR2000%20Firmware%20Version%201.2.3.7%20(WW).zip
- Local path: known_firmware/firmware/WNR2000V1/WNR2000_Firmware_Version_1.2.3.7__WW_.zip
- SHA-256: `0d84dadb4db2d533a1d9b162bcd844bfb9f367f53d2bc723abd0e0ef641841f8`
- Size: 2690852 bytes
- Version: 2.3.7__WW_
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0d84dadb4db2d533 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
