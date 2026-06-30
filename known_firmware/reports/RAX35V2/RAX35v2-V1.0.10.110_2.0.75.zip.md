# Firmware Audit: RAX35V2 / RAX35v2-V1.0.10.110_2.0.75.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX35v2/RAX35v2-V1.0.10.110_2.0.75.zip
- Local path: known_firmware/firmware/RAX35V2/RAX35v2-V1.0.10.110_2.0.75.zip
- SHA-256: `241d99df916aa5ec979ae7a2969b5013bc7dfe610bbf78da3c0fe111173f4c34`
- Size: 75932442 bytes
- Version: 1.0.10.110_2.0.75
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/241d99df916aa5ec exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
