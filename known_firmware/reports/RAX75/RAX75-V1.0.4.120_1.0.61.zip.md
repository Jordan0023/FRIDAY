# Firmware Audit: RAX75 / RAX75-V1.0.4.120_1.0.61.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX75/RAX75-V1.0.4.120_1.0.61.zip
- Local path: known_firmware/firmware/RAX75/RAX75-V1.0.4.120_1.0.61.zip
- SHA-256: `d9cbe881fa2e6868213b998509bb8586c100482f09d9a45f463c20728f9c7b9c`
- Size: 78863824 bytes
- Version: 1.0.4.120_1.0.61
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d9cbe881fa2e6868 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
