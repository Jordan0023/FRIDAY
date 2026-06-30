# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.1.0-1105-1667640857.img

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.1.0-1105-1667640857.img
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.1.0-1105-1667640857.img
- SHA-256: `7f85b74c8712ffd8a4a71f74957e02431e3935601477d1c969ab6859a76a8478`
- Size: 50724864 bytes
- Version: 4.1.0
- Release date: 2022-11-05 17:34:17

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, bOA, bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7f85b74c8712ffd8 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
