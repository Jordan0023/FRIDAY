# Firmware Audit: GL.iNet GL-AXT1800 Slate AX / openwrt-axt1800-4.4.6-0908-1694157838.img

- Source URL: https://fw.gl-inet.com/firmware/axt1800/release/openwrt-axt1800-4.4.6-0908-1694157838.img
- Local path: known_firmware/firmware/GL.iNet_GL-AXT1800_Slate_AX/openwrt-axt1800-4.4.6-0908-1694157838.img
- SHA-256: `57c909834036f24260da9264e075f02cbcd1892338b0272db9bebc8117ad2b52`
- Size: 61736735 bytes
- Version: 4.4.6
- Release date: 2023-09-08 15:22:24

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/57c909834036f242 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
