# Firmware Audit: GL.iNet GL-BE9300 Flint 3 / openwrt-be9300-4.7.14-0721-1753082869.bin

- Source URL: https://fw.gl-inet.com/firmware/be9300/release/openwrt-be9300-4.7.14-0721-1753082869.bin
- Local path: known_firmware/firmware/GL.iNet_GL-BE9300_Flint_3/openwrt-be9300-4.7.14-0721-1753082869.bin
- SHA-256: `29a072ff47acbe74d07f323374d503a0c62f99c0c67ea5efcb23f6626c5532c8`
- Size: 80422948 bytes
- Version: 4.7.14
- Release date: 2025-07-21 14:44:51

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

- binwalk -eM --directory known_firmware/extracted/29a072ff47acbe74 stopped: extraction exceeded 768 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
