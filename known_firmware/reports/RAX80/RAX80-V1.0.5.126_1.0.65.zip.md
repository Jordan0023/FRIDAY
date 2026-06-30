# Firmware Audit: RAX80 / RAX80-V1.0.5.126_1.0.65.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX80/RAX80-V1.0.5.126_1.0.65.zip
- Local path: known_firmware/firmware/RAX80/RAX80-V1.0.5.126_1.0.65.zip
- SHA-256: `d6e35754a8d879dcd177977aab863f74792b998318492d4f8a5fe9aa85bf8a94`
- Size: 77677547 bytes
- Version: 1.0.5.126_1.0.65
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d6e35754a8d879dc exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
