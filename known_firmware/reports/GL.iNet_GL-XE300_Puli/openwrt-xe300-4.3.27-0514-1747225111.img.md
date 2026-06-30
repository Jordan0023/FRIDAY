# Firmware Audit: GL.iNet GL-XE300 Puli / openwrt-xe300-4.3.27-0514-1747225111.img

- Source URL: https://fw.gl-inet.com/firmware/xe300/release4/openwrt-xe300-4.3.27-0514-1747225111.img
- Local path: known_firmware/firmware/GL.iNet_GL-XE300_Puli/openwrt-xe300-4.3.27-0514-1747225111.img
- SHA-256: `9671b723708e5dc0331612082dc8d5471b863b9e3b7bb882f6c8206b5dc88b10`
- Size: 18219008 bytes
- Version: 4.3.27
- Release date: 2025-05-14 20:17:56

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9671b723708e5dc0 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
