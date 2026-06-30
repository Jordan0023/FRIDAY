# Firmware Audit: RAX54S / RAX54S-V1.0.10.110_2.0.75.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX54S/RAX54S-V1.0.10.110_2.0.75.zip
- Local path: known_firmware/firmware/RAX54S/RAX54S-V1.0.10.110_2.0.75.zip
- SHA-256: `3725d4aa90ae1cf1ebd78d6b021a54f72cad6667e8ba9c9685bd9b2f37328482`
- Size: 75932432 bytes
- Version: 1.0.10.110_2.0.75
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3725d4aa90ae1cf1 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
