# Firmware Audit: RAX50 / RAX50-V1.0.2.8_2.0.24.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX50/RAX50-V1.0.2.8_2.0.24.zip
- Local path: known_firmware/firmware/RAX50/RAX50-V1.0.2.8_2.0.24.zip
- SHA-256: `8d678c272729927d2377660aa20471628b6f4620ecb1f9c620691818de73efd6`
- Size: 65748489 bytes
- Version: 1.0.2.8_2.0.24
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/8d678c272729927d exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
