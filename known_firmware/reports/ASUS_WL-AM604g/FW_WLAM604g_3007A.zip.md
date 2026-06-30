# Firmware Audit: ASUS WL-AM604g / FW_WLAM604g_3007A.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-AM604g/FW_WLAM604g_3007A.zip
- Local path: known_firmware/firmware/ASUS_WL-AM604g/FW_WLAM604g_3007A.zip
- SHA-256: `7f22c29b8289965a2a81f77ba837e83cda51e4f17c52d28cd40728bbbf1e6ee3`
- Size: 3795972 bytes
- Version: 3.0.0.7A
- Release date: 2009/03/19

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `inetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7f22c29b8289965a exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root-0' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root-0' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
