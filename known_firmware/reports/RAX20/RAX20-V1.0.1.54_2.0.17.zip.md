# Firmware Audit: RAX20 / RAX20-V1.0.1.54_2.0.17.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX20/RAX20-V1.0.1.54_2.0.17.zip
- Local path: known_firmware/firmware/RAX20/RAX20-V1.0.1.54_2.0.17.zip
- SHA-256: `fc5d90783c3e9a9820a48773681960c7a33f445447ab0075cc64944c2f0032b6`
- Size: 51852602 bytes
- Version: 1.0.1.54_2.0.17
- Release date: unknown

## Static Findings

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/fc5d90783c3e9a98 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
