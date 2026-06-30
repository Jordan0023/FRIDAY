# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.5.0-0201-1706757612.img

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.5.0-0201-1706757612.img
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.5.0-0201-1706757612.img
- SHA-256: `252282754fd60e85b735c2736d7cb164df0c102fdb6c5641a55c6113496b3b5c`
- Size: 46399488 bytes
- Version: 4.5.0
- Release date: 2024-02-01 11:17:00

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/252282754fd60e85 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
