# Firmware Audit: GL.iNet GL-MT3000 Beryl AX / openwrt-mt3000-4.8.0-0723-1753276204.img

- Source URL: https://fw.gl-inet.com/firmware/mt3000/release/openwrt-mt3000-4.8.0-0723-1753276204.img
- Local path: known_firmware/firmware/GL.iNet_GL-MT3000_Beryl_AX/openwrt-mt3000-4.8.0-0723-1753276204.img
- SHA-256: `4ced9544682d44211c0cbdd179895def31f90533958506ee9004fa9cbd4373bc`
- Size: 63963136 bytes
- Version: 4.8.0
- Release date: 2025-07-23 20:47:20

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4ced9544682d4421 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
