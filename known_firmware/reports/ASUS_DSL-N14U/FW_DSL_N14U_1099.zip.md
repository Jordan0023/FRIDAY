# Firmware Audit: ASUS DSL-N14U / FW_DSL_N14U_1099.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N14U/FW_DSL_N14U_1099.zip
- Local path: known_firmware/firmware/ASUS_DSL-N14U/FW_DSL_N14U_1099.zip
- SHA-256: `22e16853446f1d30c031674ce385ee700b36fbed82044d8a60ccda794345e41e`
- Size: 14714625 bytes
- Version: 1.0.9.9
- Release date: 2015/08/04

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/22e16853446f1d30 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
