# Firmware Audit: ASUS WL-AM604g / FW_WL_AM604g_2034B.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-AM604g/FW_WL_AM604g_2034B.zip
- Local path: known_firmware/firmware/ASUS_WL-AM604g/FW_WL_AM604g_2034B.zip
- SHA-256: `93a57b776c85461866736828853e67aff340611b399b66f96ab4d63e89daa6ac`
- Size: 3000100 bytes
- Version: 2.0.3.4B
- Release date: 2008/12/08

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `inetd`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/93a57b776c854618 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root-0' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root-0' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
