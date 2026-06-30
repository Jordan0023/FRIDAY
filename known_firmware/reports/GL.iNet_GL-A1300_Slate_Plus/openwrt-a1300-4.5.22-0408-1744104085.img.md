# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.5.22-0408-1744104085.img

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.5.22-0408-1744104085.img
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.5.22-0408-1744104085.img
- SHA-256: `08ce571259dc5cd993a8ffcaa2887f8a625997cd79525a8dec67c0e8aacd2dee`
- Size: 47841280 bytes
- Version: 4.5.22
- Release date: 2025-04-08 17:20:43

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/08ce571259dc5cd9 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
