# Firmware Audit: ASUS DSL-N12U_C1 / FW-DSL_N12U_C1_1078.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N12U_C1/FW-DSL_N12U_C1_1078.zip
- Local path: known_firmware/firmware/ASUS_DSL-N12U_C1/FW-DSL_N12U_C1_1078.zip
- SHA-256: `fc425d653f3d5570b9c6eab960455847a3adffd3d0b86627e1457d8b5b1424a3`
- Size: 14797707 bytes
- Version: 1.0.7.8
- Release date: 2015/01/15

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/fc425d653f3d5570 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
