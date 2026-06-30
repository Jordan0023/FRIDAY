# Firmware Audit: EAX20 / EAX20-V1.0.0.36_1.0.78.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/EAX20/EAX20-V1.0.0.36_1.0.78.zip
- Local path: known_firmware/firmware/EAX20/EAX20-V1.0.0.36_1.0.78.zip
- SHA-256: `4c401eca5b3991f70647d762489f9d3bc0b5e8289b037008b0fac02280bb01dd`
- Size: 36626557 bytes
- Version: 1.0.0.36_1.0.78
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4c401eca5b3991f7 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
