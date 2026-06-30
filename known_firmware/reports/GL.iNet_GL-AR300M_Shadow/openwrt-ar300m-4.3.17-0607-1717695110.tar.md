# Firmware Audit: GL.iNet GL-AR300M Shadow / openwrt-ar300m-4.3.17-0607-1717695110.tar

- Source URL: https://fw.gl-inet.com/firmware/ar300m/nand/release4/openwrt-ar300m-4.3.17-0607-1717695110.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AR300M_Shadow/openwrt-ar300m-4.3.17-0607-1717695110.tar
- SHA-256: `027d27a479fc9cb6de51d3db00ba78935dae57ae786085cddacf3128141314a4`
- Size: 15412666 bytes
- Version: 4.3.17
- Release date: 2024-06-07 01:30:13

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/027d27a479fc9cb6 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/027d27a479fc9cb6/_openwrt-ar300m-4.3.17-0607-1717695110.tar.extracted/sysupgrade-glinet_gl-ar300m-nand/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
