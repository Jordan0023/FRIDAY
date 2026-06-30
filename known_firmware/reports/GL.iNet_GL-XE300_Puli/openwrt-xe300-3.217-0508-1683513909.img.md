# Firmware Audit: GL.iNet GL-XE300 Puli / openwrt-xe300-3.217-0508-1683513909.img

- Source URL: https://fw.gl-inet.com/firmware/xe300/release/openwrt-xe300-3.217-0508-1683513909.img
- Local path: known_firmware/firmware/GL.iNet_GL-XE300_Puli/openwrt-xe300-3.217-0508-1683513909.img
- SHA-256: `d2c206845e629f211a1b0df331ed6b2b8bc8b1b52522c39720597f8d487878fa`
- Size: 15991114 bytes
- Version: 3.217
- Release date: 2023-05-08 10:45:09

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d2c206845e629f21 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
