# Firmware Audit: RAX54SV2 / RAX54Sv2-V1.1.6.36.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX54S/RAX54Sv2-V1.1.6.36.zip
- Local path: known_firmware/firmware/RAX54SV2/RAX54Sv2-V1.1.6.36.zip
- SHA-256: `841c12d3e28ac68602e4d2c362e1844c757053cfe05faa454d863f2ad68f2c4e`
- Size: 81385778 bytes
- Version: 1.1.6.36
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/841c12d3e28ac686 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
