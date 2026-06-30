# Firmware Audit: WNDR3700V2 / WNDR3700v2_WNDR37AVv2_Firmware_Version_1.0.0.8.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNDR3700V2/WNDR3700v2%20WNDR37AVv2%20Firmware%20Version%201.0.0.8.zip
- Local path: known_firmware/firmware/WNDR3700V2/WNDR3700v2_WNDR37AVv2_Firmware_Version_1.0.0.8.zip
- SHA-256: `d9e95e4303d44d72387870d87e96a200a67071429c8821673d9c61021661645c`
- Size: 6843715 bytes
- Version: 0.0.8
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d9e95e4303d44d72 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
