# Firmware Audit: TP-Link Archer AX1800 / Archer_AX1800_USW__V5.6_250224.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202505/20250506/Archer AX1800(USW)_V5.6_250224.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX1800/Archer_AX1800_USW__V5.6_250224.zip
- SHA-256: `f6dcb2c42f2a8b1e4853526f12023127cd2aa9a1cff050e4e8f0dffdc0b2c0b3`
- Size: 24525421 bytes
- Version: V5.6_1.0.2 Build 20250224
- Release date: 2025-05-06

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f6dcb2c42f2a8b1e exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
