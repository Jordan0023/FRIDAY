# Firmware Audit: ASUS RT-N14UHP / FW_RT_N14UHP_30043808287WOWIMAX.ZIP

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/RT-N14UHP/FW_RT_N14UHP_30043808287WOWIMAX.ZIP
- Local path: known_firmware/firmware/ASUS_RT-N14UHP/FW_RT_N14UHP_30043808287WOWIMAX.ZIP
- SHA-256: `3c94e695e96b71fa82d7b1494fb04b5df6442de321da8d54058c884d840e25f0`
- Size: 15397640 bytes
- Version: 3.0.0.4.380.8287_nowimax
- Release date: 2018/05/31

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PWd`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3c94e695e96b71fa exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
