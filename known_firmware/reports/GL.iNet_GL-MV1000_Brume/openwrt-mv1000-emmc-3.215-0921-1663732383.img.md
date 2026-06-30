# Firmware Audit: GL.iNet GL-MV1000 Brume / openwrt-mv1000-emmc-3.215-0921-1663732383.img

- Source URL: https://fw.gl-inet.com/firmware/mv1000/v1/openwrt-mv1000-emmc-3.215-0921-1663732383.img
- Local path: known_firmware/firmware/GL.iNet_GL-MV1000_Brume/openwrt-mv1000-emmc-3.215-0921-1663732383.img
- SHA-256: `ece8a674f88430b474c39e2c42997f6a17267cdfe6d0d4fd5bed0ad0f8fe9876`
- Size: 43413139 bytes
- Version: 3.215
- Release date: 2022-09-21 11:53:03

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ece8a674f88430b4 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/ece8a674f88430b4/_openwrt-mv1000-emmc-3.215-0921-1663732383.img.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
