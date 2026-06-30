# Firmware Audit: GL.iNet GL-AX1800 Flint / openwrt-ax1800-4.4.6-0908-1694156657.img

- Source URL: https://fw.gl-inet.com/firmware/ax1800/v4/openwrt-ax1800-4.4.6-0908-1694156657.img
- Local path: known_firmware/firmware/GL.iNet_GL-AX1800_Flint/openwrt-ax1800-4.4.6-0908-1694156657.img
- SHA-256: `21441ec0d84cac9fe67681185e758a78b1941ae27e12dd09915a0040931c38d6`
- Size: 61738639 bytes
- Version: 4.4.6
- Release date: 2023-09-08 15:02:44

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/21441ec0d84cac9f exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
