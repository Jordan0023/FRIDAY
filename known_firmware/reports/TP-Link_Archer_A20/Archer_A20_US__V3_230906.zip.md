# Firmware Audit: TP-Link Archer A20 / Archer_A20_US__V3_230906.zip

- Source URL: https://static.tp-link.com/upload/firmware/2023/202309/20230919/Archer A20(US)_V3_230906.zip
- Local path: known_firmware/firmware/TP-Link_Archer_A20/Archer_A20_US__V3_230906.zip
- SHA-256: `af5db6f71db05cedd4d981cabedfbf41810a3b344c7634a48f7741db13e5047d`
- Size: 31559802 bytes
- Version: V3.6_1.0.5 Build 20230906
- Release date: 2023-09-19

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/af5db6f71db05ced exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
