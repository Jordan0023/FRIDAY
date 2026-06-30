# Firmware Audit: ASUS DSL-N12U_C1 / FW_DSL_N12U_C1_1099.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N12U_C1/FW_DSL_N12U_C1_1099.zip
- Local path: known_firmware/firmware/ASUS_DSL-N12U_C1/FW_DSL_N12U_C1_1099.zip
- SHA-256: `1db4300962cc1fa1446a9498e9e5ec7269f5addf9d371bf3cac39b52e12db2c1`
- Size: 14706566 bytes
- Version: 1.0.9.9
- Release date: 2015/08/25

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA, Boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1db4300962cc1fa1 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
