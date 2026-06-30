# Firmware Audit: RAX80 / RAX80-V1.0.10.140.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX80/RAX80-V1.0.10.140.zip
- Local path: known_firmware/firmware/RAX80/RAX80-V1.0.10.140.zip
- SHA-256: `e78e6eff5a69fa3bf2c33f38b9c40c29f25dbbfa59e1d6ad83b296d4a53baa21`
- Size: 73506880 bytes
- Version: 1.0.10.140
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e78e6eff5a69fa3b exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
