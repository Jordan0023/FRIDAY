# Firmware Audit: WNDR3300V2 / WNDR3300v2_Initial_Firmware_Version_1.0.0.26.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNDR3300v2/WNDR3300v2%20Initial%20Firmware%20Version%201.0.0.26.zip
- Local path: known_firmware/firmware/WNDR3300V2/WNDR3300v2_Initial_Firmware_Version_1.0.0.26.zip
- SHA-256: `ab2cb23b077aef838c7b8ea1583ec8b0b464e78b5a0baf556067df5503d33ea0`
- Size: 4522053 bytes
- Version: 0.0.26
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ab2cb23b077aef83 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
