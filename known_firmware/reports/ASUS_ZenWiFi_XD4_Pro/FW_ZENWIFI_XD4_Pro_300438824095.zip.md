# Firmware Audit: ASUS ZenWiFi XD4 Pro / FW_ZENWIFI_XD4_Pro_300438824095.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/ZenWiFi_XD4_Pro/FW_ZENWIFI_XD4_Pro_300438824095.zip
- Local path: known_firmware/firmware/ASUS_ZenWiFi_XD4_Pro/FW_ZENWIFI_XD4_Pro_300438824095.zip
- SHA-256: `db7ca739046786ea067af4d56bf234ee6146ff9c95338b41838e0ebe5423a80e`
- Size: 38573981 bytes
- Version: 3.0.0.4.388_24095
- Release date: 2025/11/25

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, bOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/db7ca739046786ea stopped: extraction exceeded 1024 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
