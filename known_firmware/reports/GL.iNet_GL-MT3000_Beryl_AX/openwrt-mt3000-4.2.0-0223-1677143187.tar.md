# Firmware Audit: GL.iNet GL-MT3000 Beryl AX / openwrt-mt3000-4.2.0-0223-1677143187.tar

- Source URL: https://fw.gl-inet.com/firmware/mt3000/release/openwrt-mt3000-4.2.0-0223-1677143187.tar
- Local path: known_firmware/firmware/GL.iNet_GL-MT3000_Beryl_AX/openwrt-mt3000-4.2.0-0223-1677143187.tar
- SHA-256: `62e47c1fb29e6ae7db42199f2a1e56f43eb5b6b5685bf8d9bf7f371a2596a80d`
- Size: 62302034 bytes
- Version: 4.2.0
- Release date: 2023-02-23 17:04:11

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

- binwalk -eM --directory known_firmware/extracted/62e47c1fb29e6ae7 stopped: extraction exceeded 768 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
