# Firmware Audit: RAX75 / RAX75-V1.0.6.138.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX75/RAX75-V1.0.6.138.zip
- Local path: known_firmware/firmware/RAX75/RAX75-V1.0.6.138.zip
- SHA-256: `e6c51a6bd3516cb21fe9247ed90e3e3f9219dcf9a1ba72bd3c3cdf1f06b06dba`
- Size: 73274260 bytes
- Version: 1.0.6.138
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e6c51a6bd3516cb2 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
