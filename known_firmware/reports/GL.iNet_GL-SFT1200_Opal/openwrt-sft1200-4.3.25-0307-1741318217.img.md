# Firmware Audit: GL.iNet GL-SFT1200 Opal / openwrt-sft1200-4.3.25-0307-1741318217.img

- Source URL: https://fw.gl-inet.com/firmware/sft1200/release4/openwrt-sft1200-4.3.25-0307-1741318217.img
- Local path: known_firmware/firmware/GL.iNet_GL-SFT1200_Opal/openwrt-sft1200-4.3.25-0307-1741318217.img
- SHA-256: `095e16f4d4c30e62ad016636337d1e5acee94fa81cd113722aa5a45707da0399`
- Size: 19660800 bytes
- Version: 4.3.25
- Release date: 2025-03-07 11:19:12

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/095e16f4d4c30e62 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
