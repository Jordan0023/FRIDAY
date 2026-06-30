# Firmware Audit: EAX80 / EAX80-V1.0.0.36_1.0.1.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX80/EAX80-V1.0.0.36_1.0.1.zip
- Local path: known_firmware/firmware/EAX80/EAX80-V1.0.0.36_1.0.1.zip
- SHA-256: `13c1d1852d74cbb7ab24a14b61177ce3d832b666c0d5d5db968f482b9a2f83c7`
- Size: 35179081 bytes
- Version: 1.0.0.36_1.0.1
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/13c1d1852d74cbb7 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
