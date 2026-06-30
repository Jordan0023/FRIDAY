# Firmware Audit: GL.iNet GL-X750 Spitz / openwrt-x750-4.0-release20317-0607-1717707440.bin

- Source URL: https://fw.gl-inet.com/firmware/x750/release4/openwrt-x750-4.0-release20317-0607-1717707440.bin
- Local path: known_firmware/firmware/GL.iNet_GL-X750_Spitz/openwrt-x750-4.0-release20317-0607-1717707440.bin
- SHA-256: `184e48c6dd5befbb7fe5ea91968f96bf4bce369bb39407d0e17df0183aee808b`
- Size: 14943676 bytes
- Version: 4.3.17
- Release date: 2024-06-07 04:55:42

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/184e48c6dd5befbb exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/184e48c6dd5befbb/_openwrt-x750-4.0-release20317-0607-1717707440.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
