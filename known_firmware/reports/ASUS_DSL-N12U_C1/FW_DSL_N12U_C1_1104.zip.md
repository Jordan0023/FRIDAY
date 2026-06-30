# Firmware Audit: ASUS DSL-N12U_C1 / FW_DSL_N12U_C1_1104.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N12U_C1/FW_DSL_N12U_C1_1104.zip
- Local path: known_firmware/firmware/ASUS_DSL-N12U_C1/FW_DSL_N12U_C1_1104.zip
- SHA-256: `3abd27ea9854ddb4658e65f916169293c96bb8453bdb50151f6b88dd8a5d3f5a`
- Size: 14719629 bytes
- Version: 1.1.0.4
- Release date: 2015/11/04

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3abd27ea9854ddb4 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
