# Firmware Audit: RAX40V2 / RAX40v2-V1.0.9.108_2.0.74.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX40v2/RAX40v2-V1.0.9.108_2.0.74.zip
- Local path: known_firmware/firmware/RAX40V2/RAX40v2-V1.0.9.108_2.0.74.zip
- SHA-256: `2224c0907d02b7991fc3cefc85b764a253d84bc68d1007c15e1df3af5ee0ff03`
- Size: 75939527 bytes
- Version: 1.0.9.108_2.0.74
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2224c0907d02b799 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
