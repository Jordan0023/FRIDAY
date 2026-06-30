# Firmware Audit: GL.iNet GL-X750 Spitz / openwrt-x750-3.217-0508-1683513468.bin

- Source URL: https://fw.gl-inet.com/firmware/x750/release/openwrt-x750-3.217-0508-1683513468.bin
- Local path: known_firmware/firmware/GL.iNet_GL-X750_Spitz/openwrt-x750-3.217-0508-1683513468.bin
- SHA-256: `ff062ea6f5f528e7825c690c3bcbf4f768606e944ec5e155cd78567b44fdb22b`
- Size: 13107520 bytes
- Version: 3.217
- Release date: 2023-05-08 10:37:48

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ff062ea6f5f528e7 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/ff062ea6f5f528e7/_openwrt-x750-3.217-0508-1683513468.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
