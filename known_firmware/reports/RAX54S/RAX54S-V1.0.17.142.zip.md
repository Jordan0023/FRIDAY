# Firmware Audit: RAX54S / RAX54S-V1.0.17.142.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX54S/RAX54S-V1.0.17.142.zip
- Local path: known_firmware/firmware/RAX54S/RAX54S-V1.0.17.142.zip
- SHA-256: `7fcf618f27a2c11f0080099a9a4441063dc67b775d57fe879b41c465c65987fd`
- Size: 81328181 bytes
- Version: 1.0.17.142
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7fcf618f27a2c11f exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
