# Firmware Audit: WNR1000V3 / WNR1000v3_Firmware_Version_1.0.2.18__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR1000v3/WNR1000v3%20Firmware%20Version%201.0.2.18%20(North%20America).zip
- Local path: known_firmware/firmware/WNR1000V3/WNR1000v3_Firmware_Version_1.0.2.18__North_America_.zip
- SHA-256: `5e518ae04d0a8e7ae2a6ecb585acf6765701629616b69836df274b64988fc81a`
- Size: 2602166 bytes
- Version: 0.2.18__North_America_
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5e518ae04d0a8e7a exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
