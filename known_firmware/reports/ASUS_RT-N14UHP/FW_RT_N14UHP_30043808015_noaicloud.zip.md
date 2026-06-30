# Firmware Audit: ASUS RT-N14UHP / FW_RT_N14UHP_30043808015_noaicloud.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/RT-N14UHP/FW_RT_N14UHP_30043808015_noaicloud.zip
- Local path: known_firmware/firmware/ASUS_RT-N14UHP/FW_RT_N14UHP_30043808015_noaicloud.zip
- SHA-256: `f834a8d55bee7c7ec371864fb6689f311c19ab4c3fe0e13be359b18b93716dd2`
- Size: 13489223 bytes
- Version: 3.0.0.4.380.8015_noaicloud
- Release date: 2017/08/25

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PWd`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f834a8d55bee7c7e exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
