# Firmware Audit: RAX45 / RAX45-V1.0.2.64_2.0.41.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX45/RAX45-V1.0.2.64_2.0.41.zip
- Local path: known_firmware/firmware/RAX45/RAX45-V1.0.2.64_2.0.41.zip
- SHA-256: `2f904656974f1fba299643ef90e156f143db8cf69e830bd7d3176daac79a4eb4`
- Size: 65574342 bytes
- Version: 1.0.2.64_2.0.41
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2f904656974f1fba exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
