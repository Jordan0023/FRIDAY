# Firmware Audit: GL.iNet GL-MT2500/GL-MT2500A Brume 2 / openwrt-mt2500-4.7.0-1205-1733363804.bin

- Source URL: https://fw.gl-inet.com/firmware/mt2500/release/openwrt-mt2500-4.7.0-1205-1733363804.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT2500_GL-MT2500A_Brume_2/openwrt-mt2500-4.7.0-1205-1733363804.bin
- SHA-256: `201ec244f73c6f49a85a1e1622d3136d65f0a2c58279c3cb94e1ecd7b017c6f0`
- Size: 54448839 bytes
- Version: 4.7.0
- Release date: 2024-12-05 09:28:39

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/201ec244f73c6f49 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/201ec244f73c6f49/_openwrt-mt2500-4.7.0-1205-1733363804.bin.extracted/sysupgrade-glinet_gl-mt2500/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
