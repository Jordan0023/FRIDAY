# Firmware Audit: RAX41 / RAX41-V1.0.4.100_2.0.64.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX41/RAX41-V1.0.4.100_2.0.64.zip
- Local path: known_firmware/firmware/RAX41/RAX41-V1.0.4.100_2.0.64.zip
- SHA-256: `64d71b47771e1dad7a68177c98e324ef03397297a9b8b031a5a01d1d2f7a951c`
- Size: 74003223 bytes
- Version: 1.0.4.100_2.0.64
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/64d71b47771e1dad exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
