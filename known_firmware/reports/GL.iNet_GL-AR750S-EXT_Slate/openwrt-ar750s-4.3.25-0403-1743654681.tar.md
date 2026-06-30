# Firmware Audit: GL.iNet GL-AR750S-EXT Slate / openwrt-ar750s-4.3.25-0403-1743654681.tar

- Source URL: https://fw.gl-inet.com/firmware/ar750s/release4/openwrt-ar750s-4.3.25-0403-1743654681.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AR750S-EXT_Slate/openwrt-ar750s-4.3.25-0403-1743654681.tar
- SHA-256: `41146b67407b85ca900656be40c6f95e6121de884415a70064124096fe5d9fd0`
- Size: 16251803 bytes
- Version: 4.3.25
- Release date: 2025-04-03 12:30:46

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, Boa, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/41146b67407b85ca exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/41146b67407b85ca/_openwrt-ar750s-4.3.25-0403-1743654681.tar.extracted/sysupgrade-glinet_gl-ar750s-nor-nand/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
