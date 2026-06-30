# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.5.16-0321-1711027287.img

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.5.16-0321-1711027287.img
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.5.16-0321-1711027287.img
- SHA-256: `41090f62103802bed6432ea19ee046a451dd32510c3606c95c87b32b46347f41`
- Size: 47710208 bytes
- Version: 4.5.16
- Release date: 2024-03-21 21:19:35

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/41090f62103802be exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
