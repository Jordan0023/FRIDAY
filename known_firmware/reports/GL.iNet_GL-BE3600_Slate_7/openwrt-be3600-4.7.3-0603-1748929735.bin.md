# Firmware Audit: GL.iNet GL-BE3600 Slate 7 / openwrt-be3600-4.7.3-0603-1748929735.bin

- Source URL: https://fw.gl-inet.com/firmware/be3600/release/openwrt-be3600-4.7.3-0603-1748929735.bin
- Local path: known_firmware/firmware/GL.iNet_GL-BE3600_Slate_7/openwrt-be3600-4.7.3-0603-1748929735.bin
- SHA-256: `8bf0a97817b41cdf9b541692405067e25747128ae9cecb102b1fadedcca623b8`
- Size: 87296559 bytes
- Version: 4.7.3
- Release date: 2025-06-03 13:22:02

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/8bf0a97817b41cdf exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
