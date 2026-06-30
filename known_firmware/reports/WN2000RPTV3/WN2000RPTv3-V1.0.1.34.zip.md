# Firmware Audit: WN2000RPTV3 / WN2000RPTv3-V1.0.1.34.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WN2000RPTV3/WN2000RPTv3-V1.0.1.34.zip
- Local path: known_firmware/firmware/WN2000RPTV3/WN2000RPTv3-V1.0.1.34.zip
- SHA-256: `63b6b1cdb88608ef721bc5873de69768d3f800d0842c68982a3bd003211a366c`
- Size: 3481261 bytes
- Version: 1.0.1.34
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/63b6b1cdb88608ef exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
