# Firmware Audit: ASUS RT-N14UHP / FW_RT_N14UHP_30043808287WOAICLOUD.ZIP

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/RT-N14UHP/FW_RT_N14UHP_30043808287WOAICLOUD.ZIP
- Local path: known_firmware/firmware/ASUS_RT-N14UHP/FW_RT_N14UHP_30043808287WOAICLOUD.ZIP
- SHA-256: `d3d27a33c2b1851c6fabb0b7bffd36a8ab77cd31aa1354c14b96996624aea4ba`
- Size: 13493823 bytes
- Version: 3.0.0.4.380.8287_noaicloud
- Release date: 2018/05/31

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PWd`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d3d27a33c2b1851c exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
