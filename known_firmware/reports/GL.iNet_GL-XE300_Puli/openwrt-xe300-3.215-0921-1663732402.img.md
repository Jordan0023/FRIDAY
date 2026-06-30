# Firmware Audit: GL.iNet GL-XE300 Puli / openwrt-xe300-3.215-0921-1663732402.img

- Source URL: https://fw.gl-inet.com/firmware/xe300/release/openwrt-xe300-3.215-0921-1663732402.img
- Local path: known_firmware/firmware/GL.iNet_GL-XE300_Puli/openwrt-xe300-3.215-0921-1663732402.img
- SHA-256: `c4a859b9570489ffcb4217e7b2aff5ef32f44e092ef72a67a7de9cf42deb1c7a`
- Size: 15991114 bytes
- Version: 3.215
- Release date: 2022-09-21 11:53:22

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, bOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c4a859b9570489ff exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
