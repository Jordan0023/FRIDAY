# Firmware Audit: RAX35V2 / RAX35v2_V1.0.2.82_2.0.50.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX35v2/RAX35v2_V1.0.2.82_2.0.50.zip
- Local path: known_firmware/firmware/RAX35V2/RAX35v2_V1.0.2.82_2.0.50.zip
- SHA-256: `8de0edeba5da8a962cd93a31401a476b7aaa180a5fc8a379f8d5253f81f4e2d1`
- Size: 70834688 bytes
- Version: 0.2.82_2.0.50
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/8de0edeba5da8a96 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
