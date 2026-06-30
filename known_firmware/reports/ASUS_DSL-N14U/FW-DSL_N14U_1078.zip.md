# Firmware Audit: ASUS DSL-N14U / FW-DSL_N14U_1078.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N14U/FW-DSL_N14U_1078.zip
- Local path: known_firmware/firmware/ASUS_DSL-N14U/FW-DSL_N14U_1078.zip
- SHA-256: `a739756c50af6c06f7803f469bc86bc7297efcf20186adf6f3eef4297b27f6fa`
- Size: 14795664 bytes
- Version: 1.0.7.8
- Release date: 2015/01/15

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a739756c50af6c06 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
