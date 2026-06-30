# Firmware Audit: ASUS DSL-N12E / FW_DSL_N12E_2116_APAC.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N12E/FW_DSL_N12E_2116_APAC.zip
- Local path: known_firmware/firmware/ASUS_DSL-N12E/FW_DSL_N12E_2116_APAC.zip
- SHA-256: `21b45f101d6b7eba14b6928e938cb25daad633e34a5b9135e000d80658bbe35e`
- Size: 1347966 bytes
- Version: 2.1.16
- Release date: 2014/01/15

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/21b45f101d6b7eba exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
