# Firmware Audit: GL.iNet GL-AXT1800 Slate AX / openwrt-axt1800-4.0.2-0817-1660708548.img

- Source URL: https://fw.gl-inet.com/firmware/axt1800/release/openwrt-axt1800-4.0.2-0817-1660708548.img
- Local path: known_firmware/firmware/GL.iNet_GL-AXT1800_Slate_AX/openwrt-axt1800-4.0.2-0817-1660708548.img
- SHA-256: `3e169e427b28be60d0b2a135c8271323d51aef6006433478e67ab870d2ec2de0`
- Size: 51644191 bytes
- Version: 4.0.2
- Release date: 2022-08-17 11:55:48

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa, bOA, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3e169e427b28be60 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
