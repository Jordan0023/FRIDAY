# Firmware Audit: GL.iNet GL-MT300N / openwrt-mt300n-2.265.bin

- Source URL: https://fw.gl-inet.com/firmware/mt300n/v1/openwrt-mt300n-2.265.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT300N/openwrt-mt300n-2.265.bin
- SHA-256: `c97724654d9a3a60081bb4db40399d5a406661945cb3de48e10b496984667f4b`
- Size: 9437188 bytes
- Version: 2.265
- Release date: 2025-07-02 14:12:30

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `password`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c97724654d9a3a60 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/c97724654d9a3a60/_openwrt-mt300n-2.265.bin.extracted/squashfs-root-0/usr/lib/libglutil.so -> /usr/lib/gl/libglutil.so; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
