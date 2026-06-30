# Firmware Audit: TP-Link Archer AX21 / Archer_AX21_US__V5.6_250224.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202505/20250506/Archer AX21(US)_V5.6_250224.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX21/Archer_AX21_US__V5.6_250224.zip
- SHA-256: `021103002dbf716c12fc1dc0c0cf581de5eeb57a1ceea7c9f2f7a0cb8467a89d`
- Size: 24525417 bytes
- Version: V5.6_1.0.2 Build 20250224
- Release date: 2025-05-06

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/021103002dbf716c exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
