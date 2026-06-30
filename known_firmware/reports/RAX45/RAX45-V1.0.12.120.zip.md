# Firmware Audit: RAX45 / RAX45-V1.0.12.120.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX45/RAX45-V1.0.12.120.zip
- Local path: known_firmware/firmware/RAX45/RAX45-V1.0.12.120.zip
- SHA-256: `76017bec729d96362d2095827e4aad6a8e6aaa2cd6398bc24f8317d46ae53199`
- Size: 82214910 bytes
- Version: 1.0.12.120
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/76017bec729d9636 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
