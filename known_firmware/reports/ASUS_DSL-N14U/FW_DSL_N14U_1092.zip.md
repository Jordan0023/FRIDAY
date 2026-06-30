# Firmware Audit: ASUS DSL-N14U / FW_DSL_N14U_1092.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N14U/FW_DSL_N14U_1092.zip
- Local path: known_firmware/firmware/ASUS_DSL-N14U/FW_DSL_N14U_1092.zip
- SHA-256: `8b1df53c70cdfb2dfcb915d904baacd9f71a3444a827cd22a8503cc9196dde0c`
- Size: 14630636 bytes
- Version: 1.0.9.2
- Release date: 2015/04/22

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/8b1df53c70cdfb2d exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
