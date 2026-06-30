# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.2.0-0309-1678376771.img

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.2.0-0309-1678376771.img
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.2.0-0309-1678376771.img
- SHA-256: `cb43dc0b62996854230615c0b5d83d6b0df08b8eb1332c809e068e8507806dc1`
- Size: 60030976 bytes
- Version: 4.2.0
- Release date: 2023-03-09 23:44:24

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/cb43dc0b62996854 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
