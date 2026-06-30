# Firmware Audit: ASUS 4G-N12 B1 / FW_4G_N12_B1_firmware_update.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/4G-N12_B1/FW_4G_N12_B1_firmware_update.zip
- Local path: known_firmware/firmware/ASUS_4G-N12_B1/FW_4G_N12_B1_firmware_update.zip
- SHA-256: `ea01710edfc18091d48e2ba2aa4fce69f9b8ce8924c6d36986ad061033caf940`
- Size: 39403350 bytes
- Version: vP01_06
- Release date: 2021/05/28

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PWD`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ea01710edfc18091 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
