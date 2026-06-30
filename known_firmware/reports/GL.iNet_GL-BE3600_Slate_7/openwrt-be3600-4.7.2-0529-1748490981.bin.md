# Firmware Audit: GL.iNet GL-BE3600 Slate 7 / openwrt-be3600-4.7.2-0529-1748490981.bin

- Source URL: https://fw.gl-inet.com/firmware/be3600/release/openwrt-be3600-4.7.2-0529-1748490981.bin
- Local path: known_firmware/firmware/GL.iNet_GL-BE3600_Slate_7/openwrt-be3600-4.7.2-0529-1748490981.bin
- SHA-256: `82982408bb4ca0c2e5c99d20784a2dde934a817a0dc01b4832519265d4bb77ad`
- Size: 87300069 bytes
- Version: 4.7.2
- Release date: 2025-05-29 11:27:03

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/82982408bb4ca0c2 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
