# Firmware Audit: EAX20 / EAX20-V1.0.0.48_1.0.93.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX20/EAX20-V1.0.0.48_1.0.93.zip
- Local path: known_firmware/firmware/EAX20/EAX20-V1.0.0.48_1.0.93.zip
- SHA-256: `022c3784e2c77d58efcdf11c6afb1373d6d6db3de5010b441289ee8b8f35515d`
- Size: 34028921 bytes
- Version: 1.0.0.48_1.0.93
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/022c3784e2c77d58 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
