# Firmware Audit: GL.iNet GL-MT3000 Beryl AX / openwrt-mt3000-4.1.3-0112-1673519726.img

- Source URL: https://fw.gl-inet.com/firmware/mt3000/release/openwrt-mt3000-4.1.3-0112-1673519726.img
- Local path: known_firmware/firmware/GL.iNet_GL-MT3000_Beryl_AX/openwrt-mt3000-4.1.3-0112-1673519726.img
- SHA-256: `e02941ab13d00269a7861230bd02c11b7c80b08260172e0799476d8474bbace0`
- Size: 55574528 bytes
- Version: 4.1.3
- Release date: 2023-01-12 18:51:32

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e02941ab13d00269 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
