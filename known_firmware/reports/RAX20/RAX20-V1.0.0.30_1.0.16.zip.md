# Firmware Audit: RAX20 / RAX20-V1.0.0.30_1.0.16.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX20/RAX20-V1.0.0.30_1.0.16.zip
- Local path: known_firmware/firmware/RAX20/RAX20-V1.0.0.30_1.0.16.zip
- SHA-256: `e6770bf3c38ab4732a7c98dd4f2bf30fd0973a28935cd65a987dc0dd96a372d2`
- Size: 51109889 bytes
- Version: 1.0.0.30_1.0.16
- Release date: unknown

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `sSHD`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e6770bf3c38ab473 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
