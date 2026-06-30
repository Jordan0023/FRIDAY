# Firmware Audit: TP-Link Archer C8 / Archer_C8_US__V4.0_220510.zip

- Source URL: https://static.tp-link.com/upload/firmware/2022/202209/20220913/Archer C8(US)_V4.0_220510.zip
- Local path: known_firmware/firmware/TP-Link_Archer_C8/Archer_C8_US__V4.0_220510.zip
- SHA-256: `a3127143d50acbfe9f879f61982361d359db71f9476a491fe53837c6fbf0ac97`
- Size: 27449325 bytes
- Version: V4_1.0.2 Build 20220510
- Release date: 2022-09-13

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a3127143d50acbfe exited 0: WARNING: Extractor.execute failed to run external extractor 'jefferson -d 'jffs2-root' '%e'': [Errno 2] No such file or directory: 'jefferson', 'jefferson -d 'jffs2-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
