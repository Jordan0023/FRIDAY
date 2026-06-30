# Firmware Audit: GL.iNet GL-AR300M Shadow / openwrt-ar300m-4.3.11-0320-1710941767.tar

- Source URL: https://fw.gl-inet.com/firmware/ar300m/nand/release4/openwrt-ar300m-4.3.11-0320-1710941767.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AR300M_Shadow/openwrt-ar300m-4.3.11-0320-1710941767.tar
- SHA-256: `fdfe8a2fea5ed3cae563bf995e3c6c0306847a66d686f0db2db10698229aa030`
- Size: 15382344 bytes
- Version: 4.3.11
- Release date: 2024-03-20 21:34:30

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/fdfe8a2fea5ed3ca exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/fdfe8a2fea5ed3ca/_openwrt-ar300m-4.3.11-0320-1710941767.tar.extracted/sysupgrade-glinet_gl-ar300m-nand/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
