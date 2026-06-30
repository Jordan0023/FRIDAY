# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.5.17-0620-1718884660.tar

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.5.17-0620-1718884660.tar
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.5.17-0620-1718884660.tar
- SHA-256: `1dbfddd374350a706ba733e77a324e80427355c3ecf16a603cf37293a96e3cf5`
- Size: 45855593 bytes
- Version: 4.5.17
- Release date: 2024-06-20 19:55:43

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1dbfddd374350a70 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/1dbfddd374350a70/_openwrt-a1300-4.5.17-0620-1718884660.tar.extracted/sysupgrade-glinet_gl-a1300/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
