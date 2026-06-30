# Firmware Audit: GL.iNet GL-MT2500/GL-MT2500A Brume 2 / openwrt-mt2500-4.7.4-0328-1743128340.bin

- Source URL: https://fw.gl-inet.com/firmware/mt2500/release/openwrt-mt2500-4.7.4-0328-1743128340.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT2500_GL-MT2500A_Brume_2/openwrt-mt2500-4.7.4-0328-1743128340.bin
- SHA-256: `3de78f88a2cc204c089cd1c262346786796d43a223564b1f792f3e8515cc8904`
- Size: 54562732 bytes
- Version: 4.7.4
- Release date: 2025-03-28 09:52:27

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3de78f88a2cc204c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/3de78f88a2cc204c/_openwrt-mt2500-4.7.4-0328-1743128340.bin.extracted/sysupgrade-glinet_gl-mt2500/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
