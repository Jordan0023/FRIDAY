# Firmware Audit: ASUS ZenWiFi XD4 Plus / FW_ZenWiFi_XD4_Plus_300438669103.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/ZenWiFi_XD4_Plus/FW_ZenWiFi_XD4_Plus_300438669103.zip
- Local path: known_firmware/firmware/ASUS_ZenWiFi_XD4_Plus/FW_ZenWiFi_XD4_Plus_300438669103.zip
- SHA-256: `a3e16bee93984fb9f78cef5b37f70aea712ca7fa7d005fc3a43b59aa243b506e`
- Size: 26231499 bytes
- Version: 3.0.0.4.386_69103
- Release date: 2025/04/18

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Pwd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a3e16bee93984fb9 stopped: extraction exceeded 1024 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
