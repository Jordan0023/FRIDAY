# Firmware Audit: GL.iNet GL-AX1800 Flint / openwrt-ax1800-4.2.0-0310-1678379767.img

- Source URL: https://fw.gl-inet.com/firmware/ax1800/v4/openwrt-ax1800-4.2.0-0310-1678379767.img
- Local path: known_firmware/firmware/GL.iNet_GL-AX1800_Flint/openwrt-ax1800-4.2.0-0310-1678379767.img
- SHA-256: `51e9d08bd8c85bdd6e65a147a24eb258d385850976c3f3ea792f6edba0e2c409`
- Size: 63180393 bytes
- Version: 4.2.0
- Release date: 2023-03-10 00:34:49

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/51e9d08bd8c85bdd exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
