# Firmware Audit: GL.iNet GL-AX1800 Flint / openwrt-ax1800-4.5.16-0321-1711030388.img

- Source URL: https://fw.gl-inet.com/firmware/ax1800/v4/openwrt-ax1800-4.5.16-0321-1711030388.img
- Local path: known_firmware/firmware/GL.iNet_GL-AX1800_Flint/openwrt-ax1800-4.5.16-0321-1711030388.img
- SHA-256: `0e14896e9a796f3ac643927d8b0d8b9e871cd8188f46f8bf12a288e60b5ca70f`
- Size: 50860173 bytes
- Version: 4.5.16
- Release date: 2024-03-21 22:11:35

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0e14896e9a796f3a exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
