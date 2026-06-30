# Firmware Audit: GL.iNet GL-MT3000 Beryl AX / openwrt-mt3000-4.2.0-0223-1677143187.img

- Source URL: https://fw.gl-inet.com/firmware/mt3000/release/openwrt-mt3000-4.2.0-0223-1677143187.img
- Local path: known_firmware/firmware/GL.iNet_GL-MT3000_Beryl_AX/openwrt-mt3000-4.2.0-0223-1677143187.img
- SHA-256: `4079ad578f13be56d24a2321ba682390246445b5532a51d84feef35c118fde73`
- Size: 65273856 bytes
- Version: 4.2.0
- Release date: 2023-02-23 17:04:11

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4079ad578f13be56 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
