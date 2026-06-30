# Firmware Audit: WNR2000V1 / WNR2000_Firmware_Version_1.2.0.8__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR2000v1/WNR2000%20Firmware%20Version%201.2.0.8%20(North%20America).zip
- Local path: known_firmware/firmware/WNR2000V1/WNR2000_Firmware_Version_1.2.0.8__North_America_.zip
- SHA-256: `c2771718f412dee20833d17055f4a53ad0c01b7807eee3b4c3b23fcedb568662`
- Size: 2742575 bytes
- Version: 2.0.8__North_America_
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c2771718f412dee2 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
