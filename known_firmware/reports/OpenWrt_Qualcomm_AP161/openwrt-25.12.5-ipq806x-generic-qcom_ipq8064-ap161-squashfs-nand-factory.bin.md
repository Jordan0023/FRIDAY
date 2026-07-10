# Firmware Audit: OpenWrt Qualcomm AP161 / openwrt-25.12.5-ipq806x-generic-qcom_ipq8064-ap161-squashfs-nand-factory.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq806x/generic/openwrt-25.12.5-ipq806x-generic-qcom_ipq8064-ap161-squashfs-nand-factory.bin
- Local path: known_firmware/firmware/OpenWrt_Qualcomm_AP161/openwrt-25.12.5-ipq806x-generic-qcom_ipq8064-ap161-squashfs-nand-factory.bin
- SHA-256: `1fb678d79802676a8133de532b6d1c4e8be09b28d77690f21d1e50eefb6ceb83`
- Size: 10485760 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1fb678d79802676a exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
