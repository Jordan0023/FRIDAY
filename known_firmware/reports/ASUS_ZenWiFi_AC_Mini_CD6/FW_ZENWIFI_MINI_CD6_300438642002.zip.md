# Firmware Audit: ASUS ZenWiFi AC Mini(CD6) / FW_ZENWIFI_MINI_CD6_300438642002.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/ZenWiFi_AC_Mini(CD6)/FW_ZENWIFI_MINI_CD6_300438642002.zip
- Local path: known_firmware/firmware/ASUS_ZenWiFi_AC_Mini_CD6/FW_ZENWIFI_MINI_CD6_300438642002.zip
- SHA-256: `17598051b6325bb8695f833aaa16488f3d7482e0228015112a62caaff8bc11f6`
- Size: 35277582 bytes
- Version: 3.0.0.4.386.42002
- Release date: 2021/08/23

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/17598051b6325bb8 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/17598051b6325bb8/_FW_ZENWIFI_MINI_CD6_300438642002.zip.extracted/_RT-AC59_CD6_3.0.0.4_386_42002-g5866f6a.trx.extracted/squashfs-root-0/usr/local/share -> /tmp/share; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
