# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.0.0-0907-1662519100.img

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.0.0-0907-1662519100.img
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.0.0-0907-1662519100.img
- SHA-256: `c68b024278a180fd429c3b368ca522f577d9905861f4287c920ca9696a9d9197`
- Size: 48365568 bytes
- Version: 4.0.0
- Release date: 2022-09-07 10:51:40

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, bOA, bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c68b024278a180fd exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
