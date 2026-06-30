# Firmware Audit: RAX35V2 / RAX35v2-V1.0.16.132.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX35v2/RAX35v2-V1.0.16.132.zip
- Local path: known_firmware/firmware/RAX35V2/RAX35v2-V1.0.16.132.zip
- SHA-256: `da50bf809957506dc7e74f00203fec80e5c23a1bce55f8ea678d0b01fa0514ea`
- Size: 84548137 bytes
- Version: 1.0.16.132
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/da50bf809957506d exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
