# Firmware Audit: WNDR37AVV2 / WNDR3700v2WNDR37AVv2_Firmware_Version_1.0.0.10.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNDR37AVv2/WNDR3700v2WNDR37AVv2%20Firmware%20Version%201.0.0.10.zip
- Local path: known_firmware/firmware/WNDR37AVV2/WNDR3700v2WNDR37AVv2_Firmware_Version_1.0.0.10.zip
- SHA-256: `06324bcb0c276fd30c2ccf5297543ad4c9512892f1e826e174e47d8aa6f54c2c`
- Size: 6842670 bytes
- Version: 0.0.10
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/06324bcb0c276fd3 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
