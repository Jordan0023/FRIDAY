# Firmware Audit: RAX54SV2 / RAX54Sv2-V1.1.4.28.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX54S/RAX54Sv2-V1.1.4.28.zip
- Local path: known_firmware/firmware/RAX54SV2/RAX54Sv2-V1.1.4.28.zip
- SHA-256: `ab99252d06d0f31c706e049f30b02c9f3ee669059f71f5dd72500477ae4b4bca`
- Size: 84776181 bytes
- Version: 1.1.4.28
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ab99252d06d0f31c exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
