# Firmware Audit: ASUS DSL-N12U_C1 / FW_DSL_N12U_C1_1097.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N12U_C1/FW_DSL_N12U_C1_1097.zip
- Local path: known_firmware/firmware/ASUS_DSL-N12U_C1/FW_DSL_N12U_C1_1097.zip
- SHA-256: `995ec34ac89b648d606a7a817263dcf64ef899bb94041ba210e60e0096731bfd`
- Size: 14722714 bytes
- Version: 1.0.9.7
- Release date: 2015/07/03

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/995ec34ac89b648d exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
