# Firmware Audit: ASUS ZenWiFi AC Mini(CD6) / FW_ZENWIFI_MINI_CD6_300438649693.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/ZenWiFi_AC_Mini(CD6)/FW_ZENWIFI_MINI_CD6_300438649693.zip
- Local path: known_firmware/firmware/ASUS_ZenWiFi_AC_Mini_CD6/FW_ZENWIFI_MINI_CD6_300438649693.zip
- SHA-256: `3e190ee20b5b71d5c485ffbf5728c6ce1e1053b3f232592a6d257961cb2e42f1`
- Size: 36152354 bytes
- Version: 3.0.0.4.386.49693
- Release date: 2022/07/21

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3e190ee20b5b71d5 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/3e190ee20b5b71d5/_FW_ZENWIFI_MINI_CD6_300438649693.zip.extracted/_RT-AC59_CD6_3.0.0.4_386_49693-gecfd731.trx.extracted/squashfs-root-0/usr/local/share -> /tmp/share; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
