# Firmware Audit: RAXE300 / RAXE300-V1.0.8.64_3.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAXE300/RAXE300-V1.0.8.64_3.zip
- Local path: known_firmware/firmware/RAXE300/RAXE300-V1.0.8.64_3.zip
- SHA-256: `9dcf9a8280fd895ffc5b3a754b96c6e4a5168a6a9041aa4c293174885d75d0cb`
- Size: 65968938 bytes
- Version: 1.0.8.64_3
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `password`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `cgi-bin, lighttpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `Eval, Popen, SYSTEM, System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9dcf9a8280fd895f exited 0: WARNING: Extractor.execute failed to run external extractor 'lzop -f -d '%e'': [Errno 2] No such file or directory: 'lzop', 'lzop -f -d '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
