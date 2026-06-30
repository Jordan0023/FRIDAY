# Firmware Audit: WNDR37AVV1 / WNDR3700_WNDR37AV_Firmware_Version_1.0.16.98NA.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNDR37AVv1/WNDR3700_WNDR37AV%20Firmware%20Version%201.0.16.98NA.zip
- Local path: known_firmware/firmware/WNDR37AVV1/WNDR3700_WNDR37AV_Firmware_Version_1.0.16.98NA.zip
- SHA-256: `25738c43436b0d2d6cfd3bfa8964eb3ed9b0b7ea6de7d4537bfd95aa01afb9f5`
- Size: 6616217 bytes
- Version: 0.16.98NA
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/25738c43436b0d2d exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
