# Firmware Audit: ASUS WL-320gE / WL320gE_1979_EN_TW_CN_KR.rar

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-320gE/WL320gE_1979_EN_TW_CN_KR.rar
- Local path: known_firmware/firmware/ASUS_WL-320gE/WL320gE_1979_EN_TW_CN_KR.rar
- SHA-256: `e2752e10c680c61133fc3ff647bf6d4580bb90f9e4daa3b7a2b4594cc3697093`
- Size: 3420445 bytes
- Version: 1.9.7.9
- Release date: 2007/08/23

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e2752e10c680c611 exited 0: WARNING: Extractor.execute failed to run external extractor 'unrar -x '%e'': [Errno 2] No such file or directory: 'unrar', 'unrar -x '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
