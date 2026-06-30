# Firmware Audit: RAX70 / RAX70-V1.0.14.134.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX70/RAX70-V1.0.14.134.zip
- Local path: known_firmware/firmware/RAX70/RAX70-V1.0.14.134.zip
- SHA-256: `e219d0b32586257ac04fcd185572db08be8bd4763837de417ed7a2b4b2a3c36c`
- Size: 67574499 bytes
- Version: 1.0.14.134
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e219d0b32586257a exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
