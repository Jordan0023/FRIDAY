# Firmware Audit: GL.iNet GL-E750/GL-E750V2 Mudi / openwrt-e750-4.0-release10318-0823-1724405846.tar

- Source URL: https://fw.gl-inet.com/firmware/e750/release4/openwrt-e750-4.0-release10318-0823-1724405846.tar
- Local path: known_firmware/firmware/GL.iNet_GL-E750_GL-E750V2_Mudi/openwrt-e750-4.0-release10318-0823-1724405846.tar
- SHA-256: `b08ef453337b8ff68e637a3e160db7ea710cf10b3f90af7fd9962ac565caba2b`
- Size: 18381665 bytes
- Version: 4.3.18
- Release date: 2024-08-23 17:35:14

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b08ef453337b8ff6 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/b08ef453337b8ff6/_openwrt-e750-4.0-release10318-0823-1724405846.tar.extracted/sysupgrade-glinet_gl-e750/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
