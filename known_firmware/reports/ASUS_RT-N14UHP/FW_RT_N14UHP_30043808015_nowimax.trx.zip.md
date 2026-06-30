# Firmware Audit: ASUS RT-N14UHP / FW_RT_N14UHP_30043808015_nowimax.trx.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/RT-N14UHP/FW_RT_N14UHP_30043808015_nowimax.trx.zip
- Local path: known_firmware/firmware/ASUS_RT-N14UHP/FW_RT_N14UHP_30043808015_nowimax.trx.zip
- SHA-256: `6e9f5c6e01f4225e14aab5bb47ce2488312c7ce168517755a93b0566c3d964f4`
- Size: 15391426 bytes
- Version: 3.0.0.4.380.8015_nowimax
- Release date: 2017/08/25

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PWd`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6e9f5c6e01f4225e exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
