# Firmware Audit: GL.iNet GL-XE300 Puli / openwrt-xe300-3.216-0321-1679391529.tar

- Source URL: https://fw.gl-inet.com/firmware/xe300/release/openwrt-xe300-3.216-0321-1679391529.tar
- Local path: known_firmware/firmware/GL.iNet_GL-XE300_Puli/openwrt-xe300-3.216-0321-1679391529.tar
- SHA-256: `80bcd19865c2b6c7346062d9bd7d4f6ce5806ab394c9eddb4eeb4fedd29661d0`
- Size: 13046090 bytes
- Version: 3.216
- Release date: 2023-03-21 17:38:49

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/80bcd19865c2b6c7 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/80bcd19865c2b6c7/_openwrt-xe300-3.216-0321-1679391529.tar.extracted/sysupgrade-glinet_gl-xe300-nor-nand/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
