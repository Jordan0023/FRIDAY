# Firmware Audit: RAX50 / RAX50-V1.0.10.110_2.0.75.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX50/RAX50-V1.0.10.110_2.0.75.zip
- Local path: known_firmware/firmware/RAX50/RAX50-V1.0.10.110_2.0.75.zip
- SHA-256: `1c9cc9c86dd628862c02f9be1eff89efa2aaa6785df731cbbe23d1f57d4e2721`
- Size: 75932433 bytes
- Version: 1.0.10.110_2.0.75
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1c9cc9c86dd62886 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
