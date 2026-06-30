# Firmware Audit: GL.iNet GL-XE3000 Puli AX / openwrt-xe3000-4.0-0403release6-1026-1698319593.bin

- Source URL: https://fw.gl-inet.com/firmware/xe3000/release/openwrt-xe3000-4.0-0403release6-1026-1698319593.bin
- Local path: known_firmware/firmware/GL.iNet_GL-XE3000_Puli_AX/openwrt-xe3000-4.0-0403release6-1026-1698319593.bin
- SHA-256: `a30156f5af4d7e496e488e0577438edf0865fb544649591b5b1b1baacf6c09b9`
- Size: 61471651 bytes
- Version: 4.4.3
- Release date: 2023-10-26 19:23:48

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

- binwalk -eM --directory known_firmware/extracted/a30156f5af4d7e49 stopped: extraction exceeded 768 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
