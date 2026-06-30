# Firmware Audit: RAX42V2 / RAX42v2-V1.1.4.28.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX42/RAX42v2-V1.1.4.28.zip
- Local path: known_firmware/firmware/RAX42V2/RAX42v2-V1.1.4.28.zip
- SHA-256: `7772228d41bdc3cee04a099c7906fd107919b98f7f0e5343d05c822504a5e9cc`
- Size: 84776178 bytes
- Version: 1.1.4.28
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7772228d41bdc3ce exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
