# Firmware Audit: RAX40V2 / RAX40v2-V1.0.17.142.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX40v2/RAX40v2-V1.0.17.142.zip
- Local path: known_firmware/firmware/RAX40V2/RAX40v2-V1.0.17.142.zip
- SHA-256: `c58647ba7d333a148d416fd5d7405a2e3b0a0fc8611c5c7f941fdf97aabf13e1`
- Size: 81328203 bytes
- Version: 1.0.17.142
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c58647ba7d333a14 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
