# Firmware Audit: RAX80 / RAX80-V1.0.3.102_1.0.48.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX80/RAX80-V1.0.3.102_1.0.48.zip
- Local path: known_firmware/firmware/RAX80/RAX80-V1.0.3.102_1.0.48.zip
- SHA-256: `2f61415e8bc89541558479f4d862c3e3d820f601d7ba95b201c3778828c8e018`
- Size: 75137354 bytes
- Version: 1.0.3.102_1.0.48
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2f61415e8bc89541 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
