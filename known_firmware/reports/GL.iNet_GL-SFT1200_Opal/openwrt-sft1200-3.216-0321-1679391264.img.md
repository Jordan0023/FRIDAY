# Firmware Audit: GL.iNet GL-SFT1200 Opal / openwrt-sft1200-3.216-0321-1679391264.img

- Source URL: https://fw.gl-inet.com/firmware/sft1200/release/openwrt-sft1200-3.216-0321-1679391264.img
- Local path: known_firmware/firmware/GL.iNet_GL-SFT1200_Opal/openwrt-sft1200-3.216-0321-1679391264.img
- SHA-256: `928bf870e4629dd82f6b05347a145ec159b5cc5a9551b6e8e9051fd385a05be5`
- Size: 19005440 bytes
- Version: 3.216
- Release date: 2023-03-21 17:34:24

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/928bf870e4629dd8 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
