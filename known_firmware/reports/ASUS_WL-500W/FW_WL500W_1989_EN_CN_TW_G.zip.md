# Firmware Audit: ASUS WL-500W / FW_WL500W_1989_EN_CN_TW_G.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-500W/FW_WL500W_1989_EN_CN_TW_G.zip
- Local path: known_firmware/firmware/ASUS_WL-500W/FW_WL500W_1989_EN_CN_TW_G.zip
- SHA-256: `5d70d49b48311894816b807a631431008cbf5852a2d753e7bb723c6847ae7363`
- Size: 7683590 bytes
- Version: 1.9.8.9
- Release date: 2008/01/03

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `httpd`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5d70d49b48311894 stopped: extraction exceeded 1024 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
