# Firmware Audit: ASUS WL-500W / FW_WL500W_2001_EN_CN_TW_GR.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-500W/FW_WL500W_2001_EN_CN_TW_GR.zip
- Local path: known_firmware/firmware/ASUS_WL-500W/FW_WL500W_2001_EN_CN_TW_GR.zip
- SHA-256: `d1b2d4e9ae4632a64f483fd54243cbcea4ba1eda622b1a9fdd2a34b2e2a61ba2`
- Size: 7775366 bytes
- Version: 2.0.0.1
- Release date: 2008/01/31

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `httpd`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d1b2d4e9ae4632a6 stopped: extraction exceeded 1024 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
