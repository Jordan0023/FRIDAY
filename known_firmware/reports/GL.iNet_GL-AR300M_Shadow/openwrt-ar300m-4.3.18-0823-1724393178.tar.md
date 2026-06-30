# Firmware Audit: GL.iNet GL-AR300M Shadow / openwrt-ar300m-4.3.18-0823-1724393178.tar

- Source URL: https://fw.gl-inet.com/firmware/ar300m/nand/release4/openwrt-ar300m-4.3.18-0823-1724393178.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AR300M_Shadow/openwrt-ar300m-4.3.18-0823-1724393178.tar
- SHA-256: `dedf06662c5b5f67210e8110516d4514000d2be050219e22fce5815222acd7bd`
- Size: 15412058 bytes
- Version: 4.3.18
- Release date: 2024-08-23 14:04:37

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/dedf06662c5b5f67 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/dedf06662c5b5f67/_openwrt-ar300m-4.3.18-0823-1724393178.tar.extracted/sysupgrade-glinet_gl-ar300m-nand/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
