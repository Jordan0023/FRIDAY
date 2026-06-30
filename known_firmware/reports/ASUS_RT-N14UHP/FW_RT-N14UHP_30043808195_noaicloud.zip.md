# Firmware Audit: ASUS RT-N14UHP / FW_RT-N14UHP_30043808195_noaicloud.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/RT-N14UHP/FW_RT-N14UHP_30043808195_noaicloud.zip
- Local path: known_firmware/firmware/ASUS_RT-N14UHP/FW_RT-N14UHP_30043808195_noaicloud.zip
- SHA-256: `a08231cfc6ee812a0285370e7e73eb948ab4c7dad519b877dcc214dd5096be33`
- Size: 13492302 bytes
- Version: 3.0.0.4.380.8195_noaicloud
- Release date: 2018/02/09

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PWd`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a08231cfc6ee812a exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
