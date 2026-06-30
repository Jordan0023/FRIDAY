# Firmware Audit: GL.iNet GL-X3000 Spitz AX / openwrt-x3000-4.0-release50303-0614-1686733815.bin

- Source URL: https://fw.gl-inet.com/firmware/x3000/release/openwrt-x3000-4.0-release50303-0614-1686733815.bin
- Local path: known_firmware/firmware/GL.iNet_GL-X3000_Spitz_AX/openwrt-x3000-4.0-release50303-0614-1686733815.bin
- SHA-256: `a80d9cd7150e29bbba5f13cf14eaa6c7d3e975326b3fa50cbebb569039f4cf0a`
- Size: 62066001 bytes
- Version: 4.3.3
- Release date: 2023-06-14 17:07:23

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

- binwalk -eM --directory known_firmware/extracted/a80d9cd7150e29bb stopped: extraction exceeded 768 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
