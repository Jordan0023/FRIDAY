# Firmware Audit: RAXE300 / RAXE300-V1.0.7.62.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAXE300/RAXE300-V1.0.7.62.zip
- Local path: known_firmware/firmware/RAXE300/RAXE300-V1.0.7.62.zip
- SHA-256: `c7a64ddd73c799c6b8be43030c78a4b079c8efdc1ce50d675264854264a55dd8`
- Size: 65964257 bytes
- Version: 1.0.7.62
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

- binwalk -eM --directory known_firmware/extracted/c7a64ddd73c799c6 exited 0: WARNING: Extractor.execute failed to run external extractor 'lzop -f -d '%e'': [Errno 2] No such file or directory: 'lzop', 'lzop -f -d '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
