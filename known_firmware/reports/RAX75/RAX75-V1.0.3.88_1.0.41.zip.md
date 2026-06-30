# Firmware Audit: RAX75 / RAX75-V1.0.3.88_1.0.41.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX75/RAX75-V1.0.3.88_1.0.41.zip
- Local path: known_firmware/firmware/RAX75/RAX75-V1.0.3.88_1.0.41.zip
- SHA-256: `a84407b672278727c8fc34aa7d901e58e3f8e995bc5200fa0e47991ffcfb7703`
- Size: 67524224 bytes
- Version: 1.0.3.88_1.0.41
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a84407b672278727 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
