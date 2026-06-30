# Firmware Audit: RAX10 / RAX10-V1.0.3.92.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX10/RAX10-V1.0.3.92.zip
- Local path: known_firmware/firmware/RAX10/RAX10-V1.0.3.92.zip
- SHA-256: `8d701b9c6802a5353d3869e00b531c550ea80bee003fd6d1dd427d2a14006490`
- Size: 54159287 bytes
- Version: 1.0.3.92
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/8d701b9c6802a535 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
