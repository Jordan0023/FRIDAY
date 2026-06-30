# Firmware Audit: GL.iNet VIXMINI / openwrt-vixmini-3.003.bin

- Source URL: https://fw.gl-inet.com/firmware/vixmini/release/openwrt-vixmini-3.003.bin
- Local path: known_firmware/firmware/GL.iNet_VIXMINI/openwrt-vixmini-3.003.bin
- SHA-256: `27941b7765a1bee687e24408dd6a425d4c2aaa421c9a5a0d37c697abedad9afe`
- Size: 6815916 bytes
- Version: 3.003
- Release date: 2025-07-02 14:12:40

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `password`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `dropbear, telnetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boA, boa, cgi-bin, uhttpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/27941b7765a1bee6 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/27941b7765a1bee6/_openwrt-vixmini-3.003.bin.extracted/squashfs-root/bin/ps -> /usr/bin/busybox; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
