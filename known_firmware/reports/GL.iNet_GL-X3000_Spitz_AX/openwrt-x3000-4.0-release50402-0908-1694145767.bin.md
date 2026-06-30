# Firmware Audit: GL.iNet GL-X3000 Spitz AX / openwrt-x3000-4.0-release50402-0908-1694145767.bin

- Source URL: https://fw.gl-inet.com/firmware/x3000/release/openwrt-x3000-4.0-release50402-0908-1694145767.bin
- Local path: known_firmware/firmware/GL.iNet_GL-X3000_Spitz_AX/openwrt-x3000-4.0-release50402-0908-1694145767.bin
- SHA-256: `1e4ab22816a36a4d1174c04d3c14d8fa0f30eafb84b39390265a3f966809dadd`
- Size: 62301273 bytes
- Version: 4.4.2
- Release date: 2023-09-08 12:00:09

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `password`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1e4ab22816a36a4d stopped: extraction exceeded 768 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
