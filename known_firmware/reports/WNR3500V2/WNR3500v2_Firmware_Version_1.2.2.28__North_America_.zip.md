# Firmware Audit: WNR3500V2 / WNR3500v2_Firmware_Version_1.2.2.28__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR3500V2/WNR3500v2%20Firmware%20Version%201.2.2.28%20(North%20America).zip
- Local path: known_firmware/firmware/WNR3500V2/WNR3500v2_Firmware_Version_1.2.2.28__North_America_.zip
- SHA-256: `39ddde66e19d7e0d832e0d76ccb9c99c4f09bb44074de325529b218a40235090`
- Size: 3443395 bytes
- Version: 2.2.28__North_America_
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/39ddde66e19d7e0d exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
