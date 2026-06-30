# Firmware Audit: WPN824EXT / WPN824EXT_Firmware_Version_1.1.1_1.1.9__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WPN824EXT/WPN824EXT%20Firmware%20Version%201.1.1_1.1.9%20(North%20America).zip
- Local path: known_firmware/firmware/WPN824EXT/WPN824EXT_Firmware_Version_1.1.1_1.1.9__North_America_.zip
- SHA-256: `c7c532e98eb566bafc1e436c2c6842343064a5eb09dadbfab4aee311f3f49da6`
- Size: 1593611 bytes
- Version: 1.1_1.1.9__North_America_
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c7c532e98eb566ba exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
