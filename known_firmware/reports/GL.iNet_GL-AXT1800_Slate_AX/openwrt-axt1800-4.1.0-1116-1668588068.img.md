# Firmware Audit: GL.iNet GL-AXT1800 Slate AX / openwrt-axt1800-4.1.0-1116-1668588068.img

- Source URL: https://fw.gl-inet.com/firmware/axt1800/release/openwrt-axt1800-4.1.0-1116-1668588068.img
- Local path: known_firmware/firmware/GL.iNet_GL-AXT1800_Slate_AX/openwrt-axt1800-4.1.0-1116-1668588068.img
- SHA-256: `494e76609273913b9f9c811071dc6d5740911cbef4b0b998d457c53ddb081e55`
- Size: 54003487 bytes
- Version: 4.1.0
- Release date: 2022-11-16 16:39:51

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/494e76609273913b exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
