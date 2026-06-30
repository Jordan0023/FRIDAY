# Firmware Audit: RAX38V2 / RAX38v2-V1.0.2.72_2.0.45.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX38v2/RAX38v2-V1.0.2.72_2.0.45.zip
- Local path: known_firmware/firmware/RAX38V2/RAX38v2-V1.0.2.72_2.0.45.zip
- SHA-256: `f290cf2cefeb4e0db3236bdf5ad3c54fd3bdbddf56df0140015dd35329b1559b`
- Size: 68683162 bytes
- Version: 1.0.2.72_2.0.45
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f290cf2cefeb4e0d exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
