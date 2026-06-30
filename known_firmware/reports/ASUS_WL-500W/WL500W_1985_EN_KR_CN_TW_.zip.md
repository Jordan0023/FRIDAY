# Firmware Audit: ASUS WL-500W / WL500W_1985_EN_KR_CN_TW_.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-500W/WL500W_1985_EN_KR_CN_TW_.zip
- Local path: known_firmware/firmware/ASUS_WL-500W/WL500W_1985_EN_KR_CN_TW_.zip
- SHA-256: `6840e82d2de030dde7c94d733ccd6602308d5d0d6821203b274dce494a98d41b`
- Size: 7616803 bytes
- Version: 1.9.8.5
- Release date: 2007/09/03

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `httpd`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6840e82d2de030dd stopped: extraction exceeded 1024 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
