# Firmware Audit: GL.iNet GL-AX1800 Flint / openwrt-ax1800-4.6.6-0926-1727315351.tar

- Source URL: https://fw.gl-inet.com/firmware/ax1800/v4/openwrt-ax1800-4.6.6-0926-1727315351.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AX1800_Flint/openwrt-ax1800-4.6.6-0926-1727315351.tar
- SHA-256: `f1d58325de066e7c1ac20b47602ec60380a850e030207e11569abd7b95405b2a`
- Size: 47094691 bytes
- Version: 4.6.6
- Release date: 2024-09-26 09:23:31

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, Boa, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f1d58325de066e7c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/f1d58325de066e7c/_openwrt-ax1800-4.6.6-0926-1727315351.tar.extracted/sysupgrade-glinet_ax1800/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
