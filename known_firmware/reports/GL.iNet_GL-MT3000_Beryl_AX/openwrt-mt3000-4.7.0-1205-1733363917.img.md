# Firmware Audit: GL.iNet GL-MT3000 Beryl AX / openwrt-mt3000-4.7.0-1205-1733363917.img

- Source URL: https://fw.gl-inet.com/firmware/mt3000/release/openwrt-mt3000-4.7.0-1205-1733363917.img
- Local path: known_firmware/firmware/GL.iNet_GL-MT3000_Beryl_AX/openwrt-mt3000-4.7.0-1205-1733363917.img
- SHA-256: `4410a2524e3dff7b7ac48c5eda1d2265df473469acf375bf417639756d5bd26c`
- Size: 60424192 bytes
- Version: 4.7.0
- Release date: 2024-12-05 09:28:13

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4410a2524e3dff7b exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
