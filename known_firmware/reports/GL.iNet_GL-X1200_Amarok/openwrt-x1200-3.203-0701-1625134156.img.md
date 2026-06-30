# Firmware Audit: GL.iNet GL-X1200 Amarok / openwrt-x1200-3.203-0701-1625134156.img

- Source URL: https://fw.gl-inet.com/firmware/x1200/release/openwrt-x1200-3.203-0701-1625134156.img
- Local path: known_firmware/firmware/GL.iNet_GL-X1200_Amarok/openwrt-x1200-3.203-0701-1625134156.img
- SHA-256: `c80ff966395b853d9197b0fc6ae3691eca881d5056ffb6ed3167b919b462c531`
- Size: 16515402 bytes
- Version: 3.203
- Release date: 2021-07-01 18:09:16

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, bOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c80ff966395b853d exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
