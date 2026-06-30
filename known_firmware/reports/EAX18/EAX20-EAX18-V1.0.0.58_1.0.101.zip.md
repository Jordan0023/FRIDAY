# Firmware Audit: EAX18 / EAX20-EAX18-V1.0.0.58_1.0.101.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX18/EAX20-EAX18-V1.0.0.58_1.0.101.zip
- Local path: known_firmware/firmware/EAX18/EAX20-EAX18-V1.0.0.58_1.0.101.zip
- SHA-256: `52551ce1f3954ad312137b2a6df011b4474ed3efea6ecbc09575754947211c14`
- Size: 33133381 bytes
- Version: 1.0.0.58_1.0.101
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, Boa, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/52551ce1f3954ad3 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
