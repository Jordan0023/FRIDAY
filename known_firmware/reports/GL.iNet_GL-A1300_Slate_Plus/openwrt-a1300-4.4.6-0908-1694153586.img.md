# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.4.6-0908-1694153586.img

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.4.6-0908-1694153586.img
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.4.6-0908-1694153586.img
- SHA-256: `75e184c1574ad20ed71df4d7df3f44cbd3ed7e4acc44e49b094231fe3869c8f7`
- Size: 58589184 bytes
- Version: 4.4.6
- Release date: 2023-09-08 14:11:04

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/75e184c1574ad20e exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
