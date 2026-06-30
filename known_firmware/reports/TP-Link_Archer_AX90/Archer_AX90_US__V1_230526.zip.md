# Firmware Audit: TP-Link Archer AX90 / Archer_AX90_US__V1_230526.zip

- Source URL: https://static.tp-link.com/upload/firmware/2023/202306/20230616/Archer AX90(US)_V1_230526.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX90/Archer_AX90_US__V1_230526.zip
- SHA-256: `16741059dda95c02be775611292c3f7d8d816561c60d261f0b94344b3e5dc4e5`
- Size: 33695195 bytes
- Version: V1.26_1.1.12 Build 20230526
- Release date: 2023-06-16

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `ssHD`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa, bOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/16741059dda95c02 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
