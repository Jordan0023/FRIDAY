# Firmware Audit: RAX70 / RAX70-V1.0.13.128.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX70/RAX70-V1.0.13.128.zip
- Local path: known_firmware/firmware/RAX70/RAX70-V1.0.13.128.zip
- SHA-256: `28c29dfa0ebcc7464148d81be45091224a91589dee6e0f1bc6c0dc630e322b80`
- Size: 66755084 bytes
- Version: 1.0.13.128
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/28c29dfa0ebcc746 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
