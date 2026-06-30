# Firmware Audit: RAX43 / RAX43-V1.0.3.96_2.0.59.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX43/RAX43-V1.0.3.96_2.0.59.zip
- Local path: known_firmware/firmware/RAX43/RAX43-V1.0.3.96_2.0.59.zip
- SHA-256: `16870035b99aad29702c371f3ae558a21752c74b92d4008b05a765a7586fa807`
- Size: 73781624 bytes
- Version: 1.0.3.96_2.0.59
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/16870035b99aad29 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
