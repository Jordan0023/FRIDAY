# Firmware Audit: WN3000RP / WN3000RP_FirmwareVersion-1.0.1.18.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WN3000RP/WN3000RP_FirmwareVersion-1.0.1.18.zip
- Local path: known_firmware/firmware/WN3000RP/WN3000RP_FirmwareVersion-1.0.1.18.zip
- SHA-256: `4ff6d3abbd122f93cc03e84ae1d007fd3eadbdcc74f90b38b2e8643eb81f59e9`
- Size: 2643614 bytes
- Version: 1.0.1.18
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4ff6d3abbd122f93 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
