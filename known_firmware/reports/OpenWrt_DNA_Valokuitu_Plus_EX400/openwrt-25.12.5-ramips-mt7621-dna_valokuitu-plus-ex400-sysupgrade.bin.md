# Firmware Audit: OpenWrt DNA Valokuitu Plus EX400 / openwrt-25.12.5-ramips-mt7621-dna_valokuitu-plus-ex400-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-dna_valokuitu-plus-ex400-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_DNA_Valokuitu_Plus_EX400/openwrt-25.12.5-ramips-mt7621-dna_valokuitu-plus-ex400-sysupgrade.bin
- SHA-256: `20dcc4b3f360dc1af21cf2e8a8f8e4afa8a13a6b6ea6fcbbaf3c9310606ba7fc`
- Size: 15503937 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/20dcc4b3f360dc1a exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
