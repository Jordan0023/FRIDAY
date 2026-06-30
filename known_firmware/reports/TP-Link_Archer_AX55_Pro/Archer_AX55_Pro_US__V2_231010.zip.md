# Firmware Audit: TP-Link Archer AX55 Pro / Archer_AX55_Pro_US__V2_231010.zip

- Source URL: https://static.tp-link.com/upload/firmware/2023/202312/20231201/Archer AX55 Pro(US)_V2_231010.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX55_Pro/Archer_AX55_Pro_US__V2_231010.zip
- SHA-256: `865d8c5a115787fa79c24b5898536337994ce3504dc6f2c67edc38565981548e`
- Size: 29176507 bytes
- Version: V2.6_1.0.4 Build 20231010
- Release date: 2023-12-01

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/865d8c5a115787fa exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
