# Firmware Audit: ASUS ZenWiFi AC Mini(CD6) / FW_ZENWIFI_MINI_CD6_300438641995.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/ZenWiFi_AC_Mini(CD6)/FW_ZENWIFI_MINI_CD6_300438641995.zip
- Local path: known_firmware/firmware/ASUS_ZenWiFi_AC_Mini_CD6/FW_ZENWIFI_MINI_CD6_300438641995.zip
- SHA-256: `23e806f53ae777583ec6b8d1464a315c0ebea113074335e1a10b708003fac882`
- Size: 35285013 bytes
- Version: 3.0.0.4.386.41995
- Release date: 2021/05/27

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/23e806f53ae77758 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/23e806f53ae77758/_FW_ZENWIFI_MINI_CD6_300438641995.zip.extracted/_RT-AC59_CD6_3.0.0.4_386_41995-g6f7e8b0.trx.extracted/squashfs-root-0/usr/local/share -> /tmp/share; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
