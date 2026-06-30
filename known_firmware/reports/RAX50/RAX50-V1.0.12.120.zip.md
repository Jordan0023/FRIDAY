# Firmware Audit: RAX50 / RAX50-V1.0.12.120.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX50/RAX50-V1.0.12.120.zip
- Local path: known_firmware/firmware/RAX50/RAX50-V1.0.12.120.zip
- SHA-256: `b74dcbf5c16bffad7e8ec685e7a860cf07fa10869beec8f6c2802d3f89d00bca`
- Size: 82214869 bytes
- Version: 1.0.12.120
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b74dcbf5c16bffad exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
