# Firmware Audit: GL.iNet GL-AXT1800 Slate AX / openwrt-axt1800-4.2.3-0706-1688630948.img

- Source URL: https://fw.gl-inet.com/firmware/axt1800/release/openwrt-axt1800-4.2.3-0706-1688630948.img
- Local path: known_firmware/firmware/GL.iNet_GL-AXT1800_Slate_AX/openwrt-axt1800-4.2.3-0706-1688630948.img
- SHA-256: `a2793d1fe268fd7baf41a40099a05b299c5e0ea7127ce84ad3c400eb84242ec6`
- Size: 61736735 bytes
- Version: 4.2.3
- Release date: 2023-07-06 16:07:33

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a2793d1fe268fd7b exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
