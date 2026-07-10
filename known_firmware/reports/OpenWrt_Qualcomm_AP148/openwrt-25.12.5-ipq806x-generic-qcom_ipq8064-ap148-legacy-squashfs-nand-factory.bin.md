# Firmware Audit: OpenWrt Qualcomm AP148 / openwrt-25.12.5-ipq806x-generic-qcom_ipq8064-ap148-legacy-squashfs-nand-factory.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq806x/generic/openwrt-25.12.5-ipq806x-generic-qcom_ipq8064-ap148-legacy-squashfs-nand-factory.bin
- Local path: known_firmware/firmware/OpenWrt_Qualcomm_AP148/openwrt-25.12.5-ipq806x-generic-qcom_ipq8064-ap148-legacy-squashfs-nand-factory.bin
- SHA-256: `8bb3a8c070cd1998ee0421ffc0538adf694408529a9d7d5923fe5c2cb4dae1dd`
- Size: 8912896 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/8bb3a8c070cd1998 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
