# Firmware Audit: ASUS WL-500W / FW_WL500W_1988_EN_CN_TW.rar

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-500W/FW_WL500W_1988_EN_CN_TW.rar
- Local path: known_firmware/firmware/ASUS_WL-500W/FW_WL500W_1988_EN_CN_TW.rar
- SHA-256: `0dbbf319f3e08af0b385dff47dc1623680a1c60ff00129573ac482281cd6ca97`
- Size: 7636054 bytes
- Version: 1.9.8.8
- Release date: 2007/10/17

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0dbbf319f3e08af0 exited 0: WARNING: Extractor.execute failed to run external extractor 'unrar -x '%e'': [Errno 2] No such file or directory: 'unrar', 'unrar -x '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
