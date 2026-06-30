# Firmware Audit: ASUS DSL-N14U / FW_DSL_N14U_1098.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N14U/FW_DSL_N14U_1098.zip
- Local path: known_firmware/firmware/ASUS_DSL-N14U/FW_DSL_N14U_1098.zip
- SHA-256: `4d74832a2fd7497e450c0abc5dab22ca951c0a1ccbab6fbf438e0636d3c43799`
- Size: 14727022 bytes
- Version: 1.0.9.8
- Release date: 2015/08/03

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4d74832a2fd7497e exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
