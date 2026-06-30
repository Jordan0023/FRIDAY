# Firmware Audit: ASUS DSL-N14U B1 / FW_DSL_N14U_B1_1113.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N14U-B1/FW_DSL_N14U_B1_1113.zip
- Local path: known_firmware/firmware/ASUS_DSL-N14U_B1/FW_DSL_N14U_B1_1113.zip
- SHA-256: `ae0935ba5ca908c1f6e615466cd50fbaddfa1886360e511ced054f6e9478e925`
- Size: 15100906 bytes
- Version: 1.1.1.3
- Release date: 2016/07/18

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ae0935ba5ca908c1 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
