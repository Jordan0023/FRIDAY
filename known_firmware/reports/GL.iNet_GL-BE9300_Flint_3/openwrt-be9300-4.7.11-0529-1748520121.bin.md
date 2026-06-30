# Firmware Audit: GL.iNet GL-BE9300 Flint 3 / openwrt-be9300-4.7.11-0529-1748520121.bin

- Source URL: https://fw.gl-inet.com/firmware/be9300/release/openwrt-be9300-4.7.11-0529-1748520121.bin
- Local path: known_firmware/firmware/GL.iNet_GL-BE9300_Flint_3/openwrt-be9300-4.7.11-0529-1748520121.bin
- SHA-256: `ce6024fc7315c85153f07b8f29d955147447b7de07df2c1ea6fc0ed6cff669cf`
- Size: 80056426 bytes
- Version: 4.7.11
- Release date: 2025-05-29 19:35:10

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `password`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ce6024fc7315c851 stopped: extraction exceeded 768 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
