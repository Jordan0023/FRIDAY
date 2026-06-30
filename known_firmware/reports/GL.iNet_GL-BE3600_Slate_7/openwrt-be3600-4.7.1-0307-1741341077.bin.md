# Firmware Audit: GL.iNet GL-BE3600 Slate 7 / openwrt-be3600-4.7.1-0307-1741341077.bin

- Source URL: https://fw.gl-inet.com/firmware/be3600/release/openwrt-be3600-4.7.1-0307-1741341077.bin
- Local path: known_firmware/firmware/GL.iNet_GL-BE3600_Slate_7/openwrt-be3600-4.7.1-0307-1741341077.bin
- SHA-256: `df2acba0a17267b92c990bbfa77e58a5ac76154450aa10a6d1dfd1632acf8257`
- Size: 79957373 bytes
- Version: 4.7.1
- Release date: 2025-03-07 17:22:05

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/df2acba0a17267b9 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
