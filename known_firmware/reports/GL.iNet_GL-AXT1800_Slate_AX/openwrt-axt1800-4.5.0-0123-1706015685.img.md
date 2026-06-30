# Firmware Audit: GL.iNet GL-AXT1800 Slate AX / openwrt-axt1800-4.5.0-0123-1706015685.img

- Source URL: https://fw.gl-inet.com/firmware/axt1800/release/openwrt-axt1800-4.5.0-0123-1706015685.img
- Local path: known_firmware/firmware/GL.iNet_GL-AXT1800_Slate_AX/openwrt-axt1800-4.5.0-0123-1706015685.img
- SHA-256: `99eba427a33b1200fa9c479c8a4584af4d0b08f24363d8efbb29d66160a52ff2`
- Size: 49415967 bytes
- Version: 4.5.0
- Release date: 2024-01-23 21:13:10

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, Boa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/99eba427a33b1200 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
