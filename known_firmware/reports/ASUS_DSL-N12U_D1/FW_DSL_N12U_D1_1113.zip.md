# Firmware Audit: ASUS DSL-N12U D1 / FW_DSL_N12U_D1_1113.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N12U-D1/FW_DSL_N12U_D1_1113.zip
- Local path: known_firmware/firmware/ASUS_DSL-N12U_D1/FW_DSL_N12U_D1_1113.zip
- SHA-256: `4f67a6f59792dd02a81a6c964b7155f50943cf68811da000adf886cea731c0bf`
- Size: 15092681 bytes
- Version: 1.1.1.3
- Release date: 2016/08/08

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4f67a6f59792dd02 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
