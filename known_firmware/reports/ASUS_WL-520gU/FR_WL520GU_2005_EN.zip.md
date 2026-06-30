# Firmware Audit: ASUS WL-520gU / FR_WL520GU_2005_EN.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-520GU/FR_WL520GU_2005_EN.zip
- Local path: known_firmware/firmware/ASUS_WL-520gU/FR_WL520GU_2005_EN.zip
- SHA-256: `5b93336b2fcf4421bee794e0ff4096868db6f9f3dd7d853e1f2394079c73beaf`
- Size: 3975883 bytes
- Version: 2.0.0.5
- Release date: 2007/09/05

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, httpd`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5b93336b2fcf4421 stopped: extraction exceeded 1024 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
