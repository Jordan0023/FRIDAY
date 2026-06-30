# Firmware Audit: TP-Link Archer AX10000 / Archer_AX10000_US__V2.6_230111.zip

- Source URL: https://static.tp-link.com/upload/firmware/2023/202302/20230227/Archer AX10000(US)_V2.6_230111.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX10000/Archer_AX10000_US__V2.6_230111.zip
- SHA-256: `c9fbd0fe61669d106286ef7b1f6c1ec0c1fe51d6399819cc9c95910db6e219ee`
- Size: 40931710 bytes
- Version: V2.6_2.1.4 Build 20230111
- Release date: 2023-02-27

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c9fbd0fe61669d10 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
