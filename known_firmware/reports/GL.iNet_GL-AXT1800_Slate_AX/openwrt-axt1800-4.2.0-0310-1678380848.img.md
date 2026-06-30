# Firmware Audit: GL.iNet GL-AXT1800 Slate AX / openwrt-axt1800-4.2.0-0310-1678380848.img

- Source URL: https://fw.gl-inet.com/firmware/axt1800/release/openwrt-axt1800-4.2.0-0310-1678380848.img
- Local path: known_firmware/firmware/GL.iNet_GL-AXT1800_Slate_AX/openwrt-axt1800-4.2.0-0310-1678380848.img
- SHA-256: `0112ba93ff1be23ffb0783088d24c3e587e388e6fac3e05ed7374b113e788f98`
- Size: 63178527 bytes
- Version: 4.2.0
- Release date: 2023-03-10 00:52:51

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0112ba93ff1be23f exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
