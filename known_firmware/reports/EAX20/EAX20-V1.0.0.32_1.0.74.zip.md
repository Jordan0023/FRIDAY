# Firmware Audit: EAX20 / EAX20-V1.0.0.32_1.0.74.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX20/EAX20-V1.0.0.32_1.0.74.zip
- Local path: known_firmware/firmware/EAX20/EAX20-V1.0.0.32_1.0.74.zip
- SHA-256: `ebe9ffb74cdd1c8fbae4b923185fcc323811635c3f551e933c606e6fff59e459`
- Size: 36479022 bytes
- Version: 1.0.0.32_1.0.74
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ebe9ffb74cdd1c8f exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
