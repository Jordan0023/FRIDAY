# Firmware Audit: GL.iNet GL-X1200 Amarok / openwrt-x1200-3.105-1207-1607326109.img

- Source URL: https://fw.gl-inet.com/firmware/x1200/release/openwrt-x1200-3.105-1207-1607326109.img
- Local path: known_firmware/firmware/GL.iNet_GL-X1200_Amarok/openwrt-x1200-3.105-1207-1607326109.img
- SHA-256: `5547abcc3ca9371272eef00e088a6de7898039872ac357e27e3f2a66a6024dcf`
- Size: 17301504 bytes
- Version: 3.105
- Release date: 2020-12-07 15:28:29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5547abcc3ca93712 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
