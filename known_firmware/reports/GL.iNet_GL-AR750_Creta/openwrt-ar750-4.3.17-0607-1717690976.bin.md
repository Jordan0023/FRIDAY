# Firmware Audit: GL.iNet GL-AR750 Creta / openwrt-ar750-4.3.17-0607-1717690976.bin

- Source URL: https://fw.gl-inet.com/firmware/ar750/release4/openwrt-ar750-4.3.17-0607-1717690976.bin
- Local path: known_firmware/firmware/GL.iNet_GL-AR750_Creta/openwrt-ar750-4.3.17-0607-1717690976.bin
- SHA-256: `64012c9a9dcd0fec809b296d4eb2c877694b4f7b8d9dc3f34a63b5c6f47c442a`
- Size: 14878136 bytes
- Version: 4.3.17
- Release date: 2024-06-07 00:21:18

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/64012c9a9dcd0fec exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/64012c9a9dcd0fec/_openwrt-ar750-4.3.17-0607-1717690976.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
