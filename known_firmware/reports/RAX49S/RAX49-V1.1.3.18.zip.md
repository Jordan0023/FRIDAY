# Firmware Audit: RAX49S / RAX49-V1.1.3.18.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX49S/RAX49-V1.1.3.18.zip
- Local path: known_firmware/firmware/RAX49S/RAX49-V1.1.3.18.zip
- SHA-256: `3b699f58205e3188463759ce469a3875e381eaa4613c141e58ee2a1a7dc8afb1`
- Size: 81245659 bytes
- Version: 1.1.3.18
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3b699f58205e3188 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
