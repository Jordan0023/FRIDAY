# Firmware Audit: GL.iNet GL-AX1800 Flint / openwrt-ax1800-4.6.4-0904-1725458643.tar

- Source URL: https://fw.gl-inet.com/firmware/ax1800/v4/openwrt-ax1800-4.6.4-0904-1725458643.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AX1800_Flint/openwrt-ax1800-4.6.4-0904-1725458643.tar
- SHA-256: `f700427e063277373ede04c841025fe1115df4cebf39ee4f385c7677a1198417`
- Size: 47087610 bytes
- Version: 4.6.4
- Release date: 2024-09-04 21:28:16

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, Boa, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f700427e06327737 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/f700427e06327737/_openwrt-ax1800-4.6.4-0904-1725458643.tar.extracted/sysupgrade-glinet_ax1800/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
