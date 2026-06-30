# Firmware Audit: GL.iNet GL-XE300 Puli / openwrt-xe300-3.215-0921-1663732402.tar

- Source URL: https://fw.gl-inet.com/firmware/xe300/release/openwrt-xe300-3.215-0921-1663732402.tar
- Local path: known_firmware/firmware/GL.iNet_GL-XE300_Puli/openwrt-xe300-3.215-0921-1663732402.tar
- SHA-256: `de5b2d39d27b0e8ef8530119cf9a11a88dbcdfec43766c36c26a3ef5d2d6b1f3`
- Size: 13076810 bytes
- Version: 3.215
- Release date: 2022-09-21 11:53:22

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, bOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/de5b2d39d27b0e8e exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/de5b2d39d27b0e8e/_openwrt-xe300-3.215-0921-1663732402.tar.extracted/sysupgrade-glinet_gl-xe300-nor-nand/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
