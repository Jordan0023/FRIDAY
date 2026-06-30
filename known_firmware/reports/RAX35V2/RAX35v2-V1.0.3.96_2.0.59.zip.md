# Firmware Audit: RAX35V2 / RAX35v2-V1.0.3.96_2.0.59.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX35v2/RAX35v2-V1.0.3.96_2.0.59.zip
- Local path: known_firmware/firmware/RAX35V2/RAX35v2-V1.0.3.96_2.0.59.zip
- SHA-256: `5eed5e2ad5301fd5b3fa0587188cc49d4b6e63155cce7ca66c23c0e8c00c267c`
- Size: 73781637 bytes
- Version: 1.0.3.96_2.0.59
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5eed5e2ad5301fd5 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
