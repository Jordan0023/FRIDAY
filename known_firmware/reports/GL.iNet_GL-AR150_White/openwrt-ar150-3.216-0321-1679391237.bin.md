# Firmware Audit: GL.iNet GL-AR150 White / openwrt-ar150-3.216-0321-1679391237.bin

- Source URL: https://fw.gl-inet.com/firmware/ar150/v1/openwrt-ar150-3.216-0321-1679391237.bin
- Local path: known_firmware/firmware/GL.iNet_GL-AR150_White/openwrt-ar150-3.216-0321-1679391237.bin
- SHA-256: `6febbdcf75e4ca71f7c6d777e04385bb58c5238e0d46b04192cf04b316059b0e`
- Size: 12583228 bytes
- Version: 3.216
- Release date: 2023-03-21 17:33:57

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6febbdcf75e4ca71 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/6febbdcf75e4ca71/_openwrt-ar150-3.216-0321-1679391237.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
