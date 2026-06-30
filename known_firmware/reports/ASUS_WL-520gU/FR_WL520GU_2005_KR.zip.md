# Firmware Audit: ASUS WL-520gU / FR_WL520GU_2005_KR.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-520GU/FR_WL520GU_2005_KR.zip
- Local path: known_firmware/firmware/ASUS_WL-520gU/FR_WL520GU_2005_KR.zip
- SHA-256: `8c72fb927abf5ceff07666ecd22173d61c2436e2c242a2b5c5655fd7f305ce1d`
- Size: 3939457 bytes
- Version: 2.0.0.5
- Release date: 2007/09/05

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, httpd`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/8c72fb927abf5cef stopped: extraction exceeded 1024 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
