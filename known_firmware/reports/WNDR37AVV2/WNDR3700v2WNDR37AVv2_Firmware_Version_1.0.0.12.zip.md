# Firmware Audit: WNDR37AVV2 / WNDR3700v2WNDR37AVv2_Firmware_Version_1.0.0.12.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNDR37AVv2/WNDR3700v2WNDR37AVv2%20Firmware%20Version%201.0.0.12.zip
- Local path: known_firmware/firmware/WNDR37AVV2/WNDR3700v2WNDR37AVv2_Firmware_Version_1.0.0.12.zip
- SHA-256: `b6582e816d810232f6a90b4ee83f1555845192d6d0697bae114f1bbf148b6208`
- Size: 6842982 bytes
- Version: 0.0.12
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b6582e816d810232 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
