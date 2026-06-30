# Firmware Audit: ASUS DSL-N14U / FW_DSL_N14U_1104.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N14U/FW_DSL_N14U_1104.zip
- Local path: known_firmware/firmware/ASUS_DSL-N14U/FW_DSL_N14U_1104.zip
- SHA-256: `14da8498727ff0df09cded89ea4979c5503bb85f0897356da8eacf694742814d`
- Size: 14727639 bytes
- Version: 1.1.0.4
- Release date: 2015/11/04

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/14da8498727ff0df exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
