# Firmware Audit: GL.iNet GL-MT3000 Beryl AX / openwrt-mt3000-4.7.4-0328-1743128536.img

- Source URL: https://fw.gl-inet.com/firmware/mt3000/release/openwrt-mt3000-4.7.4-0328-1743128536.img
- Local path: known_firmware/firmware/GL.iNet_GL-MT3000_Beryl_AX/openwrt-mt3000-4.7.4-0328-1743128536.img
- SHA-256: `a3aafc265115d05dfa558bfc4cfed36f8c433ddfc80eb7e46d7e206bb3b5a263`
- Size: 60686336 bytes
- Version: 4.7.4
- Release date: 2025-03-28 09:53:50

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a3aafc265115d05d exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
