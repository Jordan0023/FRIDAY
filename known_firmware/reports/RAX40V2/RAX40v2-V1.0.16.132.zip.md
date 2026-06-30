# Firmware Audit: RAX40V2 / RAX40v2-V1.0.16.132.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX40v2/RAX40v2-V1.0.16.132.zip
- Local path: known_firmware/firmware/RAX40V2/RAX40v2-V1.0.16.132.zip
- SHA-256: `1c3e5e9b1822ff581dd7e0a7d49079d1476255e0dabe307ce0d9c651df99ea84`
- Size: 84548134 bytes
- Version: 1.0.16.132
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1c3e5e9b1822ff58 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
