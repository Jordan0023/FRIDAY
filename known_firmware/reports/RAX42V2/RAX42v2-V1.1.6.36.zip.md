# Firmware Audit: RAX42V2 / RAX42v2-V1.1.6.36.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX42/RAX42v2-V1.1.6.36.zip
- Local path: known_firmware/firmware/RAX42V2/RAX42v2-V1.1.6.36.zip
- SHA-256: `bb97766cd6c6900dc521359ed5e23472f38945e0bb339f221c8842a970de2fbc`
- Size: 81385783 bytes
- Version: 1.1.6.36
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/bb97766cd6c6900d exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
