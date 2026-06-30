# Firmware Audit: RAX15 / RAX15-V1.0.2.64_2.0.42.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX15/RAX15-V1.0.2.64_2.0.42.zip
- Local path: known_firmware/firmware/RAX15/RAX15-V1.0.2.64_2.0.42.zip
- SHA-256: `0560b398b0525db2621b98169c7569390d8882f9b3103c420d23cfab625caf1d`
- Size: 63595730 bytes
- Version: 1.0.2.64_2.0.42
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0560b398b0525db2 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
