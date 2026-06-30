# Firmware Audit: GL.iNet GL-XE300 Puli / openwrt-xe300-4.3.27-0514-1747225111.tar

- Source URL: https://fw.gl-inet.com/firmware/xe300/release4/openwrt-xe300-4.3.27-0514-1747225111.tar
- Local path: known_firmware/firmware/GL.iNet_GL-XE300_Puli/openwrt-xe300-4.3.27-0514-1747225111.tar
- SHA-256: `54062a62138d13a977fc2aaa8c694b655da5193e4dfaeeb6ceb953f4e30ae4ad`
- Size: 15893251 bytes
- Version: 4.3.27
- Release date: 2025-05-14 20:17:56

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/54062a62138d13a9 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/54062a62138d13a9/_openwrt-xe300-4.3.27-0514-1747225111.tar.extracted/sysupgrade-glinet_gl-xe300-nor-nand/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
