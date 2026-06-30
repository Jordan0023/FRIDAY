# Firmware Audit: RAX42 / RAX42-V1.0.17.142.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX42/RAX42-V1.0.17.142.zip
- Local path: known_firmware/firmware/RAX42/RAX42-V1.0.17.142.zip
- SHA-256: `ac84e6c41630cf620c78e34bb5f38b3e16578d93412a149b619f53e411174042`
- Size: 81328174 bytes
- Version: 1.0.17.142
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ac84e6c41630cf62 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
