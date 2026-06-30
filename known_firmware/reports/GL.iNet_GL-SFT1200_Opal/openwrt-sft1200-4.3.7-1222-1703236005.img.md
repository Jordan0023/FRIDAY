# Firmware Audit: GL.iNet GL-SFT1200 Opal / openwrt-sft1200-4.3.7-1222-1703236005.img

- Source URL: https://fw.gl-inet.com/firmware/sft1200/release4/openwrt-sft1200-4.3.7-1222-1703236005.img
- Local path: known_firmware/firmware/GL.iNet_GL-SFT1200_Opal/openwrt-sft1200-4.3.7-1222-1703236005.img
- SHA-256: `cd208e7b7e7f4c713e487c274bc81f69c5951ec8f07463ce9dc049feb62ef09a`
- Size: 19922944 bytes
- Version: 4.3.7
- Release date: 2023-12-22 17:04:10

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/cd208e7b7e7f4c71 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
