# Firmware Audit: GL.iNet GL-X3000 Spitz AX / openwrt-x3000-4.0-0413release2-1025-1729827381.bin

- Source URL: https://fw.gl-inet.com/firmware/x3000/release/openwrt-x3000-4.0-0413release2-1025-1729827381.bin
- Local path: known_firmware/firmware/GL.iNet_GL-X3000_Spitz_AX/openwrt-x3000-4.0-0413release2-1025-1729827381.bin
- SHA-256: `ad2279cca36b9730aaf73d760ecc346b75ead4f32303aed21a26b0478881f088`
- Size: 63581525 bytes
- Version: 4.4.13
- Release date: 2024-10-25 11:30:31

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

- binwalk -eM --directory known_firmware/extracted/ad2279cca36b9730 stopped: extraction exceeded 768 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
