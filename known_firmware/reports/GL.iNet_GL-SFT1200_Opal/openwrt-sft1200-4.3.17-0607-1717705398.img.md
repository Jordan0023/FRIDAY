# Firmware Audit: GL.iNet GL-SFT1200 Opal / openwrt-sft1200-4.3.17-0607-1717705398.img

- Source URL: https://fw.gl-inet.com/firmware/sft1200/release4/openwrt-sft1200-4.3.17-0607-1717705398.img
- Local path: known_firmware/firmware/GL.iNet_GL-SFT1200_Opal/openwrt-sft1200-4.3.17-0607-1717705398.img
- SHA-256: `4ccd22643136a91c3ed029ade842166724bd368bad6c359f74d6d7510e7448d8`
- Size: 19529728 bytes
- Version: 4.3.17
- Release date: 2024-06-07 04:03:16

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4ccd22643136a91c exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
