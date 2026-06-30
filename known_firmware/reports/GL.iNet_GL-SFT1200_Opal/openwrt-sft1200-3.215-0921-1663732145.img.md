# Firmware Audit: GL.iNet GL-SFT1200 Opal / openwrt-sft1200-3.215-0921-1663732145.img

- Source URL: https://fw.gl-inet.com/firmware/sft1200/release/openwrt-sft1200-3.215-0921-1663732145.img
- Local path: known_firmware/firmware/GL.iNet_GL-SFT1200_Opal/openwrt-sft1200-3.215-0921-1663732145.img
- SHA-256: `5968129d02198240a0d742fb49a6e401dce4ce525fcb3a351b82c5237d2f328e`
- Size: 19005440 bytes
- Version: 3.215
- Release date: 2022-09-21 11:49:05

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5968129d02198240 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
