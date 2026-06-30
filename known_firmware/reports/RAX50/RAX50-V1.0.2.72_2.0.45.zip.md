# Firmware Audit: RAX50 / RAX50-V1.0.2.72_2.0.45.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX50/RAX50-V1.0.2.72_2.0.45.zip
- Local path: known_firmware/firmware/RAX50/RAX50-V1.0.2.72_2.0.45.zip
- SHA-256: `b9113529965d62cb7f0d133974626cfac148bbc4a3463d1cc84d433b02bbbfa3`
- Size: 68683153 bytes
- Version: 1.0.2.72_2.0.45
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b9113529965d62cb exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
