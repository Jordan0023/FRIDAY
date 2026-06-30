# Firmware Audit: ASUS DSL-N12U_C1 / FW_DSL_N12U_C1_1112.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N12U_C1/FW_DSL_N12U_C1_1112.zip
- Local path: known_firmware/firmware/ASUS_DSL-N12U_C1/FW_DSL_N12U_C1_1112.zip
- SHA-256: `04dcbb4f5243fbbb01adecac77d57b082d82276f9e2471897361af936da82a7d`
- Size: 15018516 bytes
- Version: 1.1.1.2
- Release date: 2016/07/01

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/04dcbb4f5243fbbb exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
