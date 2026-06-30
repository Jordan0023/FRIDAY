# Firmware Audit: EAX18 / EAX20-EAX18-V1.0.1.68_1.0.106.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX18/EAX20-EAX18-V1.0.1.68_1.0.106.zip
- Local path: known_firmware/firmware/EAX18/EAX20-EAX18-V1.0.1.68_1.0.106.zip
- SHA-256: `2f116b321bbb1c7356910d34ae1efa00d60b4b4671e6c0f52ad04d89ef0d008e`
- Size: 33279444 bytes
- Version: 1.0.1.68_1.0.106
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2f116b321bbb1c73 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
