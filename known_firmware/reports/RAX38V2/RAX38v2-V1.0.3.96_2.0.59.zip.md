# Firmware Audit: RAX38V2 / RAX38v2-V1.0.3.96_2.0.59.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX38v2/RAX38v2-V1.0.3.96_2.0.59.zip
- Local path: known_firmware/firmware/RAX38V2/RAX38v2-V1.0.3.96_2.0.59.zip
- SHA-256: `0eeb4e653385256b5d233454e1591dd25a1b3a5dca42b11d57330f5e9236cf82`
- Size: 73781633 bytes
- Version: 1.0.3.96_2.0.59
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0eeb4e653385256b exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
