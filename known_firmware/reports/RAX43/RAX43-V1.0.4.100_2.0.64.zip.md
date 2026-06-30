# Firmware Audit: RAX43 / RAX43-V1.0.4.100_2.0.64.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX43/RAX43-V1.0.4.100_2.0.64.zip
- Local path: known_firmware/firmware/RAX43/RAX43-V1.0.4.100_2.0.64.zip
- SHA-256: `81e1ae734513d845e578452dd1730c91e71feec9721cc0ca9709eb982fc0fcc6`
- Size: 74003221 bytes
- Version: 1.0.4.100_2.0.64
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/81e1ae734513d845 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
