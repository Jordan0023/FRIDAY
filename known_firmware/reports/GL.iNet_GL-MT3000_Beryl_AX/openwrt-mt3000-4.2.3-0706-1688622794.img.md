# Firmware Audit: GL.iNet GL-MT3000 Beryl AX / openwrt-mt3000-4.2.3-0706-1688622794.img

- Source URL: https://fw.gl-inet.com/firmware/mt3000/release/openwrt-mt3000-4.2.3-0706-1688622794.img
- Local path: known_firmware/firmware/GL.iNet_GL-MT3000_Beryl_AX/openwrt-mt3000-4.2.3-0706-1688622794.img
- SHA-256: `e6c9f3d7b45f32554ea71787a47e6d38836622f854ba2d59f88a4b5e1e21803a`
- Size: 63832064 bytes
- Version: 4.2.3
- Release date: 2023-07-06 13:50:24

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e6c9f3d7b45f3255 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
