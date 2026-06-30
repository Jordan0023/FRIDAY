# Firmware Audit: GL.iNet GL-XE300 Puli / openwrt-xe300-3.217-0508-1683513909.tar

- Source URL: https://fw.gl-inet.com/firmware/xe300/release/openwrt-xe300-3.217-0508-1683513909.tar
- Local path: known_firmware/firmware/GL.iNet_GL-XE300_Puli/openwrt-xe300-3.217-0508-1683513909.tar
- SHA-256: `d5cfa70d2f3cfa4718009fad29188fe04163b3fdc579a803ecc76737ac3b2f8b`
- Size: 13046090 bytes
- Version: 3.217
- Release date: 2023-05-08 10:45:09

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d5cfa70d2f3cfa47 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/d5cfa70d2f3cfa47/_openwrt-xe300-3.217-0508-1683513909.tar.extracted/sysupgrade-glinet_gl-xe300-nor-nand/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
