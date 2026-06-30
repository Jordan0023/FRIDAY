# Firmware Audit: GL.iNet GL-AR750 Creta / openwrt-ar750-4.3.10-0202-1706855234.bin

- Source URL: https://fw.gl-inet.com/firmware/ar750/release4/openwrt-ar750-4.3.10-0202-1706855234.bin
- Local path: known_firmware/firmware/GL.iNet_GL-AR750_Creta/openwrt-ar750-4.3.10-0202-1706855234.bin
- SHA-256: `29adee8d851081238426edd27e1fc2025fb857c9544a919936f2de78db90a476`
- Size: 14551532 bytes
- Version: 4.3.10
- Release date: 2024-02-02 14:26:15

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/29adee8d85108123 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/29adee8d85108123/_openwrt-ar750-4.3.10-0202-1706855234.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
