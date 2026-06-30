# Firmware Audit: RAX42 / RAX42-V1.0.11.112.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX42/RAX42-V1.0.11.112.zip
- Local path: known_firmware/firmware/RAX42/RAX42-V1.0.11.112.zip
- SHA-256: `c696a0e83b96fb2d6a89b89020d267ef80a27d674d6af20c44264f51e7ec4c88`
- Size: 75405027 bytes
- Version: 1.0.11.112
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c696a0e83b96fb2d exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
