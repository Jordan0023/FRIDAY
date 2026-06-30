# Firmware Audit: GL.iNet GL-XE3000 Puli AX / openwrt-xe3000-4.0-0411release1-0824-1724464545.bin

- Source URL: https://fw.gl-inet.com/firmware/xe3000/release/openwrt-xe3000-4.0-0411release1-0824-1724464545.bin
- Local path: known_firmware/firmware/GL.iNet_GL-XE3000_Puli_AX/openwrt-xe3000-4.0-0411release1-0824-1724464545.bin
- SHA-256: `c52607a295dcd2a45623bd764d8229b6d600765d178cf822ac70e7f2a05cd647`
- Size: 59771591 bytes
- Version: 4.4.11
- Release date: 2024-08-24 09:52:54

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

- binwalk -eM --directory known_firmware/extracted/c52607a295dcd2a4 stopped: extraction exceeded 768 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
