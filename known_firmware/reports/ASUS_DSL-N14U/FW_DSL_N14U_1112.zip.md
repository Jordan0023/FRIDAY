# Firmware Audit: ASUS DSL-N14U / FW_DSL_N14U_1112.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N14U/FW_DSL_N14U_1112.zip
- Local path: known_firmware/firmware/ASUS_DSL-N14U/FW_DSL_N14U_1112.zip
- SHA-256: `c348622138a7bca696627f0a63da6a12196f787f3ccc3b79655f08918dd51a33`
- Size: 15031203 bytes
- Version: 1.1.1.2
- Release date: 2016/07/01

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c348622138a7bca6 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
