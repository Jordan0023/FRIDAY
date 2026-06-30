# Firmware Audit: GL.iNet GL-AX1800 Flint / openwrt-ax1800-4.6.2-0709-1720532668.img

- Source URL: https://fw.gl-inet.com/firmware/ax1800/v4/openwrt-ax1800-4.6.2-0709-1720532668.img
- Local path: known_firmware/firmware/GL.iNet_GL-AX1800_Flint/openwrt-ax1800-4.6.2-0709-1720532668.img
- SHA-256: `7782494b60538e83d1b73eb2b2db79c86fee671ce7f3dba440743edd6eb4a415`
- Size: 48896368 bytes
- Version: 4.6.2
- Release date: 2024-07-09 21:08:26

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, Boa, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7782494b60538e83 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
