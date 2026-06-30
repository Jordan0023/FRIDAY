# Firmware Audit: RAX35V2 / RAX35v2-V1.0.5.106_2.0.70.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX35v2/RAX35v2-V1.0.5.106_2.0.70.zip
- Local path: known_firmware/firmware/RAX35V2/RAX35v2-V1.0.5.106_2.0.70.zip
- SHA-256: `b735689f8dd4697b2afa9b059fd7dac46e2fda732116675af10c4a7bd432f453`
- Size: 75894296 bytes
- Version: 1.0.5.106_2.0.70
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b735689f8dd4697b exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
