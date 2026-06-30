# Firmware Audit: GL.iNet GL-XE300 Puli / openwrt-xe300-3.216-0321-1679391529.img

- Source URL: https://fw.gl-inet.com/firmware/xe300/release/openwrt-xe300-3.216-0321-1679391529.img
- Local path: known_firmware/firmware/GL.iNet_GL-XE300_Puli/openwrt-xe300-3.216-0321-1679391529.img
- SHA-256: `187660a9cf1d960c97054f7f67c4e4bd9bcb38196895ff7a55232af408402865`
- Size: 15991114 bytes
- Version: 3.216
- Release date: 2023-03-21 17:38:49

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/187660a9cf1d960c exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
