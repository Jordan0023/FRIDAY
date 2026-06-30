# Firmware Audit: GL.iNet GL-XE3000 Puli AX / openwrt-xe3000-4.0-0412release3-0925-1727240862.bin

- Source URL: https://fw.gl-inet.com/firmware/xe3000/release/openwrt-xe3000-4.0-0412release3-0925-1727240862.bin
- Local path: known_firmware/firmware/GL.iNet_GL-XE3000_Puli_AX/openwrt-xe3000-4.0-0412release3-0925-1727240862.bin
- SHA-256: `2281e655fece6cfb10b628139490f62dbd299ce563a559aebd73dbbdbc8d16d7`
- Size: 60796577 bytes
- Version: 4.4.12
- Release date: 2024-09-25 13:02:56

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

- binwalk -eM --directory known_firmware/extracted/2281e655fece6cfb stopped: extraction exceeded 768 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
