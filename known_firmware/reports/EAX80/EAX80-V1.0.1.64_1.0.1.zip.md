# Firmware Audit: EAX80 / EAX80-V1.0.1.64_1.0.1.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX80/EAX80-V1.0.1.64_1.0.1.zip
- Local path: known_firmware/firmware/EAX80/EAX80-V1.0.1.64_1.0.1.zip
- SHA-256: `c664613d12ed5a3b3ae84f5562b57c80c95525052a32818d3ea78b9b6dab6b70`
- Size: 34056710 bytes
- Version: 1.0.1.64_1.0.1
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa, bOa, boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c664613d12ed5a3b exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
