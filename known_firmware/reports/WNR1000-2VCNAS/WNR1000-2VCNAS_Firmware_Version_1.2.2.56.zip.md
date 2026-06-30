# Firmware Audit: WNR1000-2VCNAS / WNR1000-2VCNAS_Firmware_Version_1.2.2.56.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR1000-2VCNAS/WNR1000-2VCNAS%20Firmware%20Version%201.2.2.56.zip
- Local path: known_firmware/firmware/WNR1000-2VCNAS/WNR1000-2VCNAS_Firmware_Version_1.2.2.56.zip
- SHA-256: `32d84e16f878eede433c7548ac7794e230d6e37047bc5b3fdd8ed583d48d071f`
- Size: 3231452 bytes
- Version: 2.2.56
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/32d84e16f878eede exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
