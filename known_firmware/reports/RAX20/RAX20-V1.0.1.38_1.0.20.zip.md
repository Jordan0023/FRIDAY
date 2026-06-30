# Firmware Audit: RAX20 / RAX20-V1.0.1.38_1.0.20.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX20/RAX20-V1.0.1.38_1.0.20.zip
- Local path: known_firmware/firmware/RAX20/RAX20-V1.0.1.38_1.0.20.zip
- SHA-256: `db4b26c71ab243c9bd68bc1c20ff890eabd18e06c3beb25fba8cc8c15423f249`
- Size: 52081975 bytes
- Version: 1.0.1.38_1.0.20
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/db4b26c71ab243c9 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
