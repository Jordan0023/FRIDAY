# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.5.17-0620-1718884660.img

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.5.17-0620-1718884660.img
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.5.17-0620-1718884660.img
- SHA-256: `01887be23c3d05b02ad0380e62c8df313f4fbffa85f1c7e7ca408a7240f53740`
- Size: 47841280 bytes
- Version: 4.5.17
- Release date: 2024-06-20 19:55:43

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/01887be23c3d05b0 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
