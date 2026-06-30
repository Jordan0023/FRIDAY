# Firmware Audit: TP-Link Archer A20 / Archer_A20_US__V3_231010.zip

- Source URL: https://static.tp-link.com/upload/firmware/2023/202311/20231101/Archer A20(US)_V3_231010.zip
- Local path: known_firmware/firmware/TP-Link_Archer_A20/Archer_A20_US__V3_231010.zip
- SHA-256: `e5f9dcdb6804677ddcf069e4dd4cf2fc845e8a7c687dea615ffe11847ad54ea2`
- Size: 31823872 bytes
- Version: V3.6_1.0.6 Build 20231011
- Release date: 2023-11-01

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e5f9dcdb6804677d exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
