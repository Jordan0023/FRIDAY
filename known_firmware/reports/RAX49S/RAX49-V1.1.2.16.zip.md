# Firmware Audit: RAX49S / RAX49-V1.1.2.16.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX49S/RAX49-V1.1.2.16.zip
- Local path: known_firmware/firmware/RAX49S/RAX49-V1.1.2.16.zip
- SHA-256: `ef0d8ad64b0730368b7a5c7cbd6a1cdbd032d565eed2fb1379cc23293ea1c988`
- Size: 81019524 bytes
- Version: 1.1.2.16
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ef0d8ad64b073036 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
