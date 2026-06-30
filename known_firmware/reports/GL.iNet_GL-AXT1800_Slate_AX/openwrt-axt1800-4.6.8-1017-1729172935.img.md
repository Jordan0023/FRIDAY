# Firmware Audit: GL.iNet GL-AXT1800 Slate AX / openwrt-axt1800-4.6.8-1017-1729172935.img

- Source URL: https://fw.gl-inet.com/firmware/axt1800/release/openwrt-axt1800-4.6.8-1017-1729172935.img
- Local path: known_firmware/firmware/GL.iNet_GL-AXT1800_Slate_AX/openwrt-axt1800-4.6.8-1017-1729172935.img
- SHA-256: `faef007cf2a9742908fd6b4f4f0294c023e7f4caad44918322b9e5a8ef51eed5`
- Size: 48891679 bytes
- Version: 4.6.8
- Release date: 2024-10-17 21:13:00

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, Boa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/faef007cf2a97429 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
