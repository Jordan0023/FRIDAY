# Firmware Audit: ASUS WL-AM604 / FW_WL_AM604.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-AM604/FW_WL_AM604.zip
- Local path: known_firmware/firmware/ASUS_WL-AM604/FW_WL_AM604.zip
- SHA-256: `3de2fbfe6d37ae5db9cc89a47860d0dde9dfac268b4c0ca86625f1c902890200`
- Size: 1983230 bytes
- Version: S-02-02-0H00
- Release date: 2008/11/19

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `passwd`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `inetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3de2fbfe6d37ae5d exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root-0' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root-0' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
