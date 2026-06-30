# Firmware Audit: GL.iNet GL-MT3000 Beryl AX / openwrt-mt3000-4.4.5-0811-1691754744.img

- Source URL: https://fw.gl-inet.com/firmware/mt3000/release/openwrt-mt3000-4.4.5-0811-1691754744.img
- Local path: known_firmware/firmware/GL.iNet_GL-MT3000_Beryl_AX/openwrt-mt3000-4.4.5-0811-1691754744.img
- SHA-256: `c4065f991a74fea9a681a9431f6fb70ff115dc1d52513e1506e6bf89242b3beb`
- Size: 63832064 bytes
- Version: 4.4.5
- Release date: 2023-08-11 19:49:43

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c4065f991a74fea9 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
