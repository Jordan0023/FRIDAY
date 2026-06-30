# Firmware Audit: ASUS ZenWiFi AC Mini(CD6) / FW_ZENWIFI_MINI_CD6_300438646395.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/ZenWiFi_AC_Mini(CD6)/FW_ZENWIFI_MINI_CD6_300438646395.zip
- Local path: known_firmware/firmware/ASUS_ZenWiFi_AC_Mini_CD6/FW_ZENWIFI_MINI_CD6_300438646395.zip
- SHA-256: `6cff972dcc9c023900352fc7c2f3b7c912632dd66081c79a2d88f18441b4ad32`
- Size: 35916009 bytes
- Version: 3.0.0.4.386.46395
- Release date: 2021/11/11

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6cff972dcc9c0239 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/6cff972dcc9c0239/_FW_ZENWIFI_MINI_CD6_300438646395.zip.extracted/_RT-AC59_CD6_3.0.0.4_386_46395-g1fd22d2.trx.extracted/squashfs-root-0/usr/local/share -> /tmp/share; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
