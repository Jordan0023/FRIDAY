# Firmware Audit: RAX38V2 / RAX38v2-V1.0.11.112.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX38v2/RAX38v2-V1.0.11.112.zip
- Local path: known_firmware/firmware/RAX38V2/RAX38v2-V1.0.11.112.zip
- SHA-256: `c9690afbc9aaef8ee710cd7558c1a9434240e037acfe32e38130e9d7d1e1321a`
- Size: 75405037 bytes
- Version: 1.0.11.112
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c9690afbc9aaef8e exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
