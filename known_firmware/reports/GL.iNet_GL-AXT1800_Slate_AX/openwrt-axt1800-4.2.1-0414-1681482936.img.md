# Firmware Audit: GL.iNet GL-AXT1800 Slate AX / openwrt-axt1800-4.2.1-0414-1681482936.img

- Source URL: https://fw.gl-inet.com/firmware/axt1800/release/openwrt-axt1800-4.2.1-0414-1681482936.img
- Local path: known_firmware/firmware/GL.iNet_GL-AXT1800_Slate_AX/openwrt-axt1800-4.2.1-0414-1681482936.img
- SHA-256: `11a2cceb95fc5530608ed9c58426cc07fce318ce2c34ab9cb9c84c334d0dc4eb`
- Size: 61736735 bytes
- Version: 4.2.1
- Release date: 2023-04-14 22:33:55

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/11a2cceb95fc5530 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
