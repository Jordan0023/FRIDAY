# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.5.19-0826-1724680910.img

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.5.19-0826-1724680910.img
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.5.19-0826-1724680910.img
- SHA-256: `c87b6c459f0f90abf855fd40304372b6f78471a517a868bc681db4f181fea100`
- Size: 47841280 bytes
- Version: 4.5.19
- Release date: 2024-08-26 21:59:49

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c87b6c459f0f90ab exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
