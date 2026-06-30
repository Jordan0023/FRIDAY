# Firmware Audit: ASUS DSL-N12HP / FW_DSL_N12HP_1008.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N12HP/FW_DSL_N12HP_1008.zip
- Local path: known_firmware/firmware/ASUS_DSL-N12HP/FW_DSL_N12HP_1008.zip
- SHA-256: `2e79ff2ac9b6c6543f4c88d9de9794d92eb924add324bea191196a8147550d99`
- Size: 7704208 bytes
- Version: 1.0.0.8
- Release date: 2015/11/26

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2e79ff2ac9b6c654 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
