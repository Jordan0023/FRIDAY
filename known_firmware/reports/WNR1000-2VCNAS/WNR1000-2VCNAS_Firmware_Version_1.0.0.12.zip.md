# Firmware Audit: WNR1000-2VCNAS / WNR1000-2VCNAS_Firmware_Version_1.0.0.12.zip

- Source URL: https://www.downloads.netgear.com/files/WNR1000-2VCNAS/WNR1000-2VCNAS%20Firmware%20Version%201.0.0.12.zip
- Local path: known_firmware/firmware/WNR1000-2VCNAS/WNR1000-2VCNAS_Firmware_Version_1.0.0.12.zip
- SHA-256: `0e23f53463eb0c5de3d2eec506a60b7798cd4a2b606be2665805903bdef589ce`
- Size: 2865312 bytes
- Version: 0.0.12
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0e23f53463eb0c5d exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
