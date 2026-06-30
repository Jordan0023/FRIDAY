# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.2.1-0414-1681478660.img

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.2.1-0414-1681478660.img
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.2.1-0414-1681478660.img
- SHA-256: `ee19d727a315a5ddf96aa0c0fd1f441e169773be97f691fe5c500c5fbcdb961c`
- Size: 58458112 bytes
- Version: 4.2.1
- Release date: 2023-04-14 21:22:05

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ee19d727a315a5dd exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
