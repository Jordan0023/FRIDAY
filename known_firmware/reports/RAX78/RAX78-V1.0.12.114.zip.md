# Firmware Audit: RAX78 / RAX78-V1.0.12.114.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX78/RAX78-V1.0.12.114.zip
- Local path: known_firmware/firmware/RAX78/RAX78-V1.0.12.114.zip
- SHA-256: `e477165697c3036804acaa1d5d88e9056d8dd095ce3c9095dc4b8e3cc9ef2118`
- Size: 65186963 bytes
- Version: 1.0.12.114
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e477165697c30368 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
