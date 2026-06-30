# Firmware Audit: RAX54S / RAX54S-V1.0.11.112.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX54S/RAX54S-V1.0.11.112.zip
- Local path: known_firmware/firmware/RAX54S/RAX54S-V1.0.11.112.zip
- SHA-256: `2bb9cdbf6431d58df6c2e3a9946b409a7165b93296859da497dabf7c868d48e8`
- Size: 75405033 bytes
- Version: 1.0.11.112
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2bb9cdbf6431d58d exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
