# Firmware Audit: GL.iNet GL-AX1800 Flint / openwrt-ax1800-4.6.8-1017-1729176012.img

- Source URL: https://fw.gl-inet.com/firmware/ax1800/v4/openwrt-ax1800-4.6.8-1017-1729176012.img
- Local path: known_firmware/firmware/GL.iNet_GL-AX1800_Flint/openwrt-ax1800-4.6.8-1017-1729176012.img
- SHA-256: `b7a25ae95a4a9dc8325c167fb5769d3b6a1a362976ce9bc8cff115cf1b1bd667`
- Size: 48893195 bytes
- Version: 4.6.8
- Release date: 2024-10-17 22:04:15

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, Boa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b7a25ae95a4a9dc8 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
