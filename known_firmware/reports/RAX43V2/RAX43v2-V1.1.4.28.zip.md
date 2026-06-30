# Firmware Audit: RAX43V2 / RAX43v2-V1.1.4.28.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX43/RAX43v2-V1.1.4.28.zip
- Local path: known_firmware/firmware/RAX43V2/RAX43v2-V1.1.4.28.zip
- SHA-256: `17b642c7410af5b7ddbe4497d1276fe12fc9e1dcd93b861578b027350d372cb7`
- Size: 84776179 bytes
- Version: 1.1.4.28
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/17b642c7410af5b7 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
