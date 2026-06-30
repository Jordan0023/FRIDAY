# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.2.3-0706-1688626317.img

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.2.3-0706-1688626317.img
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.2.3-0706-1688626317.img
- SHA-256: `03b963370a36a96feef5ee1bbedb76b99b0ccdb9c4b1123b7933828ef5639903`
- Size: 58458112 bytes
- Version: 4.2.3
- Release date: 2023-07-06 14:49:43

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/03b963370a36a96f exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
