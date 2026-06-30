# Firmware Audit: GL.iNet GL-SFT1200 Opal / openwrt-sft1200-4.3.24-0115-1736948303.img

- Source URL: https://fw.gl-inet.com/firmware/sft1200/release4/openwrt-sft1200-4.3.24-0115-1736948303.img
- Local path: known_firmware/firmware/GL.iNet_GL-SFT1200_Opal/openwrt-sft1200-4.3.24-0115-1736948303.img
- SHA-256: `18553e0de02a308377d13dee200894ab41254dfca701ccea892a5d038c711fe0`
- Size: 19660800 bytes
- Version: 4.3.24
- Release date: 2025-01-15 21:27:24

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/18553e0de02a3083 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
