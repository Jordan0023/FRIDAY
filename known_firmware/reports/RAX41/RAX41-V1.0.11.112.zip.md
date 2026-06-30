# Firmware Audit: RAX41 / RAX41-V1.0.11.112.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX41/RAX41-V1.0.11.112.zip
- Local path: known_firmware/firmware/RAX41/RAX41-V1.0.11.112.zip
- SHA-256: `1e8538100bf4fb830d0855d524618a2f470e90f5393753cd9b1c8bcc16f984a6`
- Size: 75405026 bytes
- Version: 1.0.11.112
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1e8538100bf4fb83 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
