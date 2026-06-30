# Firmware Audit: WN3000RP / WN3000RP_Firmware_Version_1.0.0.12_1.0.12.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WN3000RP/WN3000RP%20Firmware%20Version%201.0.0.12_1.0.12.zip
- Local path: known_firmware/firmware/WN3000RP/WN3000RP_Firmware_Version_1.0.0.12_1.0.12.zip
- SHA-256: `36f955781952299fcf55d27480df2c617d72919655e96a32568061acf7d118b5`
- Size: 2648250 bytes
- Version: 0.0.12_1.0.12
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/36f955781952299f exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
