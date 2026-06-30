# Firmware Audit: GL.iNet GL-AR750S-EXT Slate / openwrt-ar750s-4.3.17-0607-1717693049.tar

- Source URL: https://fw.gl-inet.com/firmware/ar750s/release4/openwrt-ar750s-4.3.17-0607-1717693049.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AR750S-EXT_Slate/openwrt-ar750s-4.3.17-0607-1717693049.tar
- SHA-256: `a7e2fa8a81d6c0166c0dbb9386b4b45a3c4a103bac3c0386cdc537e218e27d8e`
- Size: 16242114 bytes
- Version: 4.3.17
- Release date: 2024-06-07 00:55:52

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a7e2fa8a81d6c016 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/a7e2fa8a81d6c016/_openwrt-ar750s-4.3.17-0607-1717693049.tar.extracted/sysupgrade-glinet_gl-ar750s-nor-nand/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
