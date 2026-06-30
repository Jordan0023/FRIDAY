# Firmware Audit: WNR3500LV2 / WNR3500Lv2_Firmware_Version_1.0.0.10.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR3500LV2/WNR3500Lv2%20Firmware%20Version%201.0.0.10.zip
- Local path: known_firmware/firmware/WNR3500LV2/WNR3500Lv2_Firmware_Version_1.0.0.10.zip
- SHA-256: `18f66785d9e6a29ce23871685f37413b0ddf165df7963b8e5d5ceee4a871bb0b`
- Size: 6727368 bytes
- Version: 0.0.10
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/18f66785d9e6a29c exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
