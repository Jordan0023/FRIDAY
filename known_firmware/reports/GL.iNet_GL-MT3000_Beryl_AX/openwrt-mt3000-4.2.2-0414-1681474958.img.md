# Firmware Audit: GL.iNet GL-MT3000 Beryl AX / openwrt-mt3000-4.2.2-0414-1681474958.img

- Source URL: https://fw.gl-inet.com/firmware/mt3000/release/openwrt-mt3000-4.2.2-0414-1681474958.img
- Local path: known_firmware/firmware/GL.iNet_GL-MT3000_Beryl_AX/openwrt-mt3000-4.2.2-0414-1681474958.img
- SHA-256: `c19c52712f97dc2d0968ac8348ef27a00f6506b9f073a25ac0e8446574bf5a27`
- Size: 63832064 bytes
- Version: 4.2.2
- Release date: 2023-04-14 20:19:47

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c19c52712f97dc2d exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
