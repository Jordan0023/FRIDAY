# Firmware Audit: GL.iNet GL-SFT1200 Opal / openwrt-sft1200-4.3.21-1016-1729054354.img

- Source URL: https://fw.gl-inet.com/firmware/sft1200/release4/openwrt-sft1200-4.3.21-1016-1729054354.img
- Local path: known_firmware/firmware/GL.iNet_GL-SFT1200_Opal/openwrt-sft1200-4.3.21-1016-1729054354.img
- SHA-256: `1655adc90864572d50bd4a0ce1c061ba1d59bc36ce4850ca0674dc48493fc213`
- Size: 19660800 bytes
- Version: 4.3.21
- Release date: 2024-10-16 12:32:41

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1655adc90864572d exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
