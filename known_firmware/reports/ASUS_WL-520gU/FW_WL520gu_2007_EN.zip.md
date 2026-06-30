# Firmware Audit: ASUS WL-520gU / FW_WL520gu_2007_EN.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-520GU/FW_WL520gu_2007_EN.zip
- Local path: known_firmware/firmware/ASUS_WL-520gU/FW_WL520gu_2007_EN.zip
- SHA-256: `e5efca580f4449cf95c43ce8592b3d863a350f90a76dabb8ab030b82bf11f096`
- Size: 3973548 bytes
- Version: 2.0.0.7
- Release date: 2008/01/22

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, httpd`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e5efca580f4449cf stopped: extraction exceeded 1024 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
