# Firmware Audit: OpenWrt Compex WPQ864 / openwrt-25.12.5-ipq806x-generic-compex_wpq864-squashfs-nand-factory.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq806x/generic/openwrt-25.12.5-ipq806x-generic-compex_wpq864-squashfs-nand-factory.bin
- Local path: known_firmware/firmware/OpenWrt_Compex_WPQ864/openwrt-25.12.5-ipq806x-generic-compex_wpq864-squashfs-nand-factory.bin
- SHA-256: `57629787426e1c941a8aeb9589db4fd53acb88a5c155ed425f718a54f5fdd80a`
- Size: 9961472 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/57629787426e1c94 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
