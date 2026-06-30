# Firmware Audit: GL.iNet GL-X1200 Amarok / openwrt-x1200-3.203-0701-1625134156.tar

- Source URL: https://fw.gl-inet.com/firmware/x1200/release/openwrt-x1200-3.203-0701-1625134156.tar
- Local path: known_firmware/firmware/GL.iNet_GL-X1200_Amarok/openwrt-x1200-3.203-0701-1625134156.tar
- SHA-256: `d039372310a05f59bc75817b58007457f238e511beb3a05441fea55b4cce96a1`
- Size: 15575370 bytes
- Version: 3.203
- Release date: 2021-07-01 18:09:16

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, bOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d039372310a05f59 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/d039372310a05f59/_openwrt-x1200-3.203-0701-1625134156.tar.extracted/sysupgrade-glinet_gl-x1200-nor-nand/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
