# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.1.2-1227-1672126828.img

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.1.2-1227-1672126828.img
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.1.2-1227-1672126828.img
- SHA-256: `2ec769dac8426a58949df385b4f2f14b3f5a7d398e032bf78ebee81e1f08868e`
- Size: 50987008 bytes
- Version: 4.1.2
- Release date: 2022-12-27 15:38:51

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, bOA, bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2ec769dac8426a58 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
