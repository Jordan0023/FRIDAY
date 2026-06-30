# Firmware Audit: GL.iNet GL-X3000 Spitz AX / openwrt-x3000-4.0-0404release1-1214-1702544890.bin

- Source URL: https://fw.gl-inet.com/firmware/x3000/release/openwrt-x3000-4.0-0404release1-1214-1702544890.bin
- Local path: known_firmware/firmware/GL.iNet_GL-X3000_Spitz_AX/openwrt-x3000-4.0-0404release1-1214-1702544890.bin
- SHA-256: `49479ddaf54518fd6e47c7e4f0da8137a7fadc8c93f76c47aee6598b4d7c4fea`
- Size: 62321660 bytes
- Version: 4.4.4
- Release date: 2023-12-14 17:05:18

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

- binwalk -eM --directory known_firmware/extracted/49479ddaf54518fd stopped: extraction exceeded 768 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
