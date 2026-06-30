# Firmware Audit: GL.iNet GL-AX1800 Flint / openwrt-ax1800-4.2.3-0706-1688629702.img

- Source URL: https://fw.gl-inet.com/firmware/ax1800/v4/openwrt-ax1800-4.2.3-0706-1688629702.img
- Local path: known_firmware/firmware/GL.iNet_GL-AX1800_Flint/openwrt-ax1800-4.2.3-0706-1688629702.img
- SHA-256: `d21f1492396ffb928b5ddabbd73681c2513ccce1ea12eeb0e974d16931f64b95`
- Size: 61739014 bytes
- Version: 4.2.3
- Release date: 2023-07-06 15:46:37

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d21f1492396ffb92 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
