# Firmware Audit: RAX80 / RAX80-V1.0.6.138.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX80/RAX80-V1.0.6.138.zip
- Local path: known_firmware/firmware/RAX80/RAX80-V1.0.6.138.zip
- SHA-256: `5920263a780fe5a2f0c964e8dd2bc1a52d431614c71d32d014a8b390fe183cc2`
- Size: 73274261 bytes
- Version: 1.0.6.138
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5920263a780fe5a2 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
