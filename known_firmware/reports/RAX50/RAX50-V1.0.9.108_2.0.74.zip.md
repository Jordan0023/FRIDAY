# Firmware Audit: RAX50 / RAX50-V1.0.9.108_2.0.74.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX50/RAX50-V1.0.9.108_2.0.74.zip
- Local path: known_firmware/firmware/RAX50/RAX50-V1.0.9.108_2.0.74.zip
- SHA-256: `75fa4a8e9b20f767bb1df9403e206aa73e9dbd837b7dee8b254c68dc48ce3e6b`
- Size: 75939514 bytes
- Version: 1.0.9.108_2.0.74
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/75fa4a8e9b20f767 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
