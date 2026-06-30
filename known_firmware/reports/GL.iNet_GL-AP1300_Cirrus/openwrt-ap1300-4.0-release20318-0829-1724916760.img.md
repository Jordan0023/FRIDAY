# Firmware Audit: GL.iNet GL-AP1300 Cirrus / openwrt-ap1300-4.0-release20318-0829-1724916760.img

- Source URL: https://fw.gl-inet.com/firmware/ap1300/release4/openwrt-ap1300-4.0-release20318-0829-1724916760.img
- Local path: known_firmware/firmware/GL.iNet_GL-AP1300_Cirrus/openwrt-ap1300-4.0-release20318-0829-1724916760.img
- SHA-256: `a4084215c11d9d69997423098697125dd5f3c61e45bf2a96174bff34657f499b`
- Size: 28183145 bytes
- Version: 4.3.18
- Release date: 2024-08-29 15:30:03

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a4084215c11d9d69 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
