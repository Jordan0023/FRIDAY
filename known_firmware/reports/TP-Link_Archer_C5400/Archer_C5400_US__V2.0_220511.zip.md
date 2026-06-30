# Firmware Audit: TP-Link Archer C5400 / Archer_C5400_US__V2.0_220511.zip

- Source URL: https://static.tp-link.com/upload/firmware/2022/202207/20220715/Archer C5400(US)_V2.0_220511.zip
- Local path: known_firmware/firmware/TP-Link_Archer_C5400/Archer_C5400_US__V2.0_220511.zip
- SHA-256: `9d1f7047ed0c1acfb0291df3c542ad9756192b3697a0f8897584ca69448113ee`
- Size: 28399443 bytes
- Version: V2_1.2.6 Build 20220511
- Release date: 2022-07-15

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9d1f7047ed0c1acf exited 0: WARNING: Extractor.execute failed to run external extractor 'jefferson -d 'jffs2-root' '%e'': [Errno 2] No such file or directory: 'jefferson', 'jefferson -d 'jffs2-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
