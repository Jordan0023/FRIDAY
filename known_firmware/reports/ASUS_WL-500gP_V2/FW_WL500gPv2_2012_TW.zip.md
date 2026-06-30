# Firmware Audit: ASUS WL-500gP V2 / FW_WL500gPv2_2012_TW.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-500gPV2/FW_WL500gPv2_2012_TW.zip
- Local path: known_firmware/firmware/ASUS_WL-500gP_V2/FW_WL500gPv2_2012_TW.zip
- SHA-256: `9b59e9b727adfc1d02badaf22f67784a46d317439811d00262d6e2583aec77ec`
- Size: 7536545 bytes
- Version: 2.0.1.2
- Release date: 2008/02/13

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, bOA, httpd`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9b59e9b727adfc1d stopped: extraction exceeded 1024 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
