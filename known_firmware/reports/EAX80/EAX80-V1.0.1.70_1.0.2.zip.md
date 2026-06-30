# Firmware Audit: EAX80 / EAX80-V1.0.1.70_1.0.2.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX80/EAX80-V1.0.1.70_1.0.2.zip
- Local path: known_firmware/firmware/EAX80/EAX80-V1.0.1.70_1.0.2.zip
- SHA-256: `48db14b57631a84ddd07e2d8eaab214ed65247a9db0f3a12797f246fdd62e527`
- Size: 34070816 bytes
- Version: 1.0.1.70_1.0.2
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, Boa, bOA, bOa, boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/48db14b57631a84d exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
