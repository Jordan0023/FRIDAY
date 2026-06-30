# Firmware Audit: ASUS ZenWiFi AC Mini(CD6) / FW_ZENWIFIACMINI_CD6_300438639421.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/ZenWiFi_AC_Mini(CD6)/FW_ZENWIFIACMINI_CD6_300438639421.zip
- Local path: known_firmware/firmware/ASUS_ZenWiFi_AC_Mini_CD6/FW_ZENWIFIACMINI_CD6_300438639421.zip
- SHA-256: `e76c8f994a398f140d64e3706df6ccb189541087fa483f1450171551e25ef5d1`
- Size: 35763642 bytes
- Version: 3.0.0.4.386.39421
- Release date: 2020/09/24

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PwD`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, bOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e76c8f994a398f14 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/e76c8f994a398f14/_FW_ZENWIFIACMINI_CD6_300438639421.zip.extracted/_RT-AC59_CD6_3.0.0.4_386_39421-g4041153.trx.extracted/squashfs-root-0/usr/local/share -> /tmp/share; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
