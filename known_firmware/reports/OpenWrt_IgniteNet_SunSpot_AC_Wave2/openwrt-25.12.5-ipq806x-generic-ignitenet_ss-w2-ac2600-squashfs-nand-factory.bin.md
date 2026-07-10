# Firmware Audit: OpenWrt IgniteNet SunSpot AC Wave2 / openwrt-25.12.5-ipq806x-generic-ignitenet_ss-w2-ac2600-squashfs-nand-factory.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq806x/generic/openwrt-25.12.5-ipq806x-generic-ignitenet_ss-w2-ac2600-squashfs-nand-factory.bin
- Local path: known_firmware/firmware/OpenWrt_IgniteNet_SunSpot_AC_Wave2/openwrt-25.12.5-ipq806x-generic-ignitenet_ss-w2-ac2600-squashfs-nand-factory.bin
- SHA-256: `a4b2e212e5ad85787d42500e7a7909227a17463bc71ba0e5d36e684238f7c195`
- Size: 10485760 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a4b2e212e5ad8578 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
