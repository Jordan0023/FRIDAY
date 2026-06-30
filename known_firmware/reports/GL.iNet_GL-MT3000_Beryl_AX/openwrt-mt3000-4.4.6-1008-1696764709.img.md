# Firmware Audit: GL.iNet GL-MT3000 Beryl AX / openwrt-mt3000-4.4.6-1008-1696764709.img

- Source URL: https://fw.gl-inet.com/firmware/mt3000/release/openwrt-mt3000-4.4.6-1008-1696764709.img
- Local path: known_firmware/firmware/GL.iNet_GL-MT3000_Beryl_AX/openwrt-mt3000-4.4.6-1008-1696764709.img
- SHA-256: `f8fc92d5cef5225c9b882e27586726f2a52769c8a99e2c74d4a01c8dd9a10415`
- Size: 63832064 bytes
- Version: 4.4.6
- Release date: 2023-10-08 19:29:12

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f8fc92d5cef5225c exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
