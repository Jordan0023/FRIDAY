# Firmware Audit: RAX15 / RAX15-V1.0.1.54_2.0.17.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX15/RAX15-V1.0.1.54_2.0.17.zip
- Local path: known_firmware/firmware/RAX15/RAX15-V1.0.1.54_2.0.17.zip
- SHA-256: `d041f43943efc8086dda51480c769bb9bae5cbbb916546b6678d330af4e37ca0`
- Size: 51852603 bytes
- Version: 1.0.1.54_2.0.17
- Release date: unknown

## Static Findings

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d041f43943efc808 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
