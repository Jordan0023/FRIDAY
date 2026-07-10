# Firmware Audit: OpenWrt Genexis Pulse EX400 / openwrt-25.12.5-ramips-mt7621-genexis_pulse-ex400-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-genexis_pulse-ex400-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Genexis_Pulse_EX400/openwrt-25.12.5-ramips-mt7621-genexis_pulse-ex400-sysupgrade.bin
- SHA-256: `23e7cfab12ad84c5163fbe4c27bfb42cb2cdc1d29555f6753478f98d0464f50f`
- Size: 15503922 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/23e7cfab12ad84c5 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
