# Firmware Audit: RAX41 / RAX41-V1.0.10.110_2.0.75.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX41/RAX41-V1.0.10.110_2.0.75.zip
- Local path: known_firmware/firmware/RAX41/RAX41-V1.0.10.110_2.0.75.zip
- SHA-256: `a5f3b972386d7deda5df679b9ae5eea5b0b16fd355c454ccf68f467698654b18`
- Size: 75932432 bytes
- Version: 1.0.10.110
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a5f3b972386d7ded exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
