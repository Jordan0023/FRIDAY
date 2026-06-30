# Firmware Audit: WNDR3700V2 / WNDR3700v2_Firmware_Version_1.0.0.10_-_BETA.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNDR3700V2/WNDR3700v2%20Firmware%20Version%201.0.0.10%20-%20BETA.zip
- Local path: known_firmware/firmware/WNDR3700V2/WNDR3700v2_Firmware_Version_1.0.0.10_-_BETA.zip
- SHA-256: `fb9d56a455c989810ca09886fbf795de0b35fca07537019ef6089405feeaac41`
- Size: 6842472 bytes
- Version: 0.0.10_-_BETA
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/fb9d56a455c98981 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
