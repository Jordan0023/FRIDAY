# Firmware Audit: WN2000RPTV3 / WN2000RPTv3-V1.0.1.4.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WN2000RPTV3/WN2000RPTv3-V1.0.1.4.zip
- Local path: known_firmware/firmware/WN2000RPTV3/WN2000RPTv3-V1.0.1.4.zip
- SHA-256: `3f7541c2c411ea0939c81003a6eb89a024f5d5e6964d2bb1af0e0394bea8138c`
- Size: 3467413 bytes
- Version: 1.0.1.4
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3f7541c2c411ea09 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
