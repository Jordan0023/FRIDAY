# Firmware Audit: RAX54SV2 / RAX54Sv2-V1.1.2.16.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX54S/RAX54Sv2-V1.1.2.16.zip
- Local path: known_firmware/firmware/RAX54SV2/RAX54Sv2-V1.1.2.16.zip
- SHA-256: `4c8fb04b992d4fd3895f80cdb668b5f2b078a171b3abc4f645305d0b4fab2c1a`
- Size: 81019535 bytes
- Version: 1.1.2.16
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4c8fb04b992d4fd3 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
