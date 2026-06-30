# Firmware Audit: GL.iNet GL-AX1800 Flint / openwrt-ax1800-4.1.0-1114-1668412657.img

- Source URL: https://fw.gl-inet.com/firmware/ax1800/v4/openwrt-ax1800-4.1.0-1114-1668412657.img
- Local path: known_firmware/firmware/GL.iNet_GL-AX1800_Flint/openwrt-ax1800-4.1.0-1114-1668412657.img
- SHA-256: `6d3fcfde9f7b49aba32bce540ff698bcefc1849ae6bc8b9fc49682b123af9d56`
- Size: 54003487 bytes
- Version: 4.1.0
- Release date: 2022-11-14 15:56:24

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6d3fcfde9f7b49ab exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
