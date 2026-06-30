# Firmware Audit: GL.iNet GL-AX1800 Flint / openwrt-ax1800-4.6.8-1017-1729176012.tar

- Source URL: https://fw.gl-inet.com/firmware/ax1800/v4/openwrt-ax1800-4.6.8-1017-1729176012.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AX1800_Flint/openwrt-ax1800-4.6.8-1017-1729176012.tar
- SHA-256: `5fb897cd054c9fe6b6ff65b6567a448727b1bd51e6ff111aa58c1c7c887b8f74`
- Size: 46910956 bytes
- Version: 4.6.8
- Release date: 2024-10-17 22:04:15

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, Boa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5fb897cd054c9fe6 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/5fb897cd054c9fe6/_openwrt-ax1800-4.6.8-1017-1729176012.tar.extracted/sysupgrade-glinet_ax1800/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
