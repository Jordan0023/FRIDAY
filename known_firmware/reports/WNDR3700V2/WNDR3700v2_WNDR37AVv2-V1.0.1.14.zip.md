# Firmware Audit: WNDR3700V2 / WNDR3700v2_WNDR37AVv2-V1.0.1.14.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNDR3700V2/WNDR3700v2_WNDR37AVv2-V1.0.1.14.zip
- Local path: known_firmware/firmware/WNDR3700V2/WNDR3700v2_WNDR37AVv2-V1.0.1.14.zip
- SHA-256: `86aa3f1f9e2aa5ae223f5b1031659340cadd4033acd393ee2bf69d1c0c9ffc48`
- Size: 6841950 bytes
- Version: 1.0.1.14
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/86aa3f1f9e2aa5ae exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
