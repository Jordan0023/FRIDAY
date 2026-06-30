# Firmware Audit: ASUS ZenWiFi AC Mini(CD6) / FW_ZENWIFIACMINI_CD6_300438640611.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/ZenWiFi_AC_Mini(CD6)/FW_ZENWIFIACMINI_CD6_300438640611.zip
- Local path: known_firmware/firmware/ASUS_ZenWiFi_AC_Mini_CD6/FW_ZENWIFIACMINI_CD6_300438640611.zip
- SHA-256: `370232f6dcf2fc4cfc5d54606d827c3233327daea13579596f86dc2ce1b2287c`
- Size: 36421650 bytes
- Version: 3.0.0.4.386.40611
- Release date: 2020/11/09

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PwD`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/370232f6dcf2fc4c exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/370232f6dcf2fc4c/_FW_ZENWIFIACMINI_CD6_300438640611.zip.extracted/Firmware_Release/_RT-AC59_CD6_3.0.0.4_386_40611-g8ce5085.trx.extracted/squashfs-root-0/usr/local/share -> /tmp/share; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
