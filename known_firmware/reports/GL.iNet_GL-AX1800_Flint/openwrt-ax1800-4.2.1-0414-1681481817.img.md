# Firmware Audit: GL.iNet GL-AX1800 Flint / openwrt-ax1800-4.2.1-0414-1681481817.img

- Source URL: https://fw.gl-inet.com/firmware/ax1800/v4/openwrt-ax1800-4.2.1-0414-1681481817.img
- Local path: known_firmware/firmware/GL.iNet_GL-AX1800_Flint/openwrt-ax1800-4.2.1-0414-1681481817.img
- SHA-256: `b1fdb93ae45abf0525674e2d3a50d18464d395cf7cf8e8e5162007a47b6abaee`
- Size: 61738336 bytes
- Version: 4.2.1
- Release date: 2023-04-14 22:15:11

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b1fdb93ae45abf05 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
