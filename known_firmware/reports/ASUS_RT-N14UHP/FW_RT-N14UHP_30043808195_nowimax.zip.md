# Firmware Audit: ASUS RT-N14UHP / FW_RT-N14UHP_30043808195_nowimax.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/RT-N14UHP/FW_RT-N14UHP_30043808195_nowimax.zip
- Local path: known_firmware/firmware/ASUS_RT-N14UHP/FW_RT-N14UHP_30043808195_nowimax.zip
- SHA-256: `2d78e791fb146accd31ada6dc2a53fedc5c58236c1195dee6f71083e4c04a9a2`
- Size: 15393253 bytes
- Version: 3.0.0.4.380.8195_nowimax
- Release date: 2018/02/09

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PWd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2d78e791fb146acc exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
