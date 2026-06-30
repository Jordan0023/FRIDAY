# Firmware Audit: GL.iNet GL-AX1800 Flint / openwrt-ax1800-4.6.4-0904-1725458643.img

- Source URL: https://fw.gl-inet.com/firmware/ax1800/v4/openwrt-ax1800-4.6.4-0904-1725458643.img
- Local path: known_firmware/firmware/GL.iNet_GL-AX1800_Flint/openwrt-ax1800-4.6.4-0904-1725458643.img
- SHA-256: `5bf7a8bca5228cfe2598cb765eed311fc38f5ab6175b6bd2f659533c8602b52b`
- Size: 49026841 bytes
- Version: 4.6.4
- Release date: 2024-09-04 21:28:16

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, Boa, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5bf7a8bca5228cfe exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
