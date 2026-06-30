# Firmware Audit: GL.iNet GL-AR750S-EXT Slate / openwrt-ar750s-4.3.11-0320-1710950296.tar

- Source URL: https://fw.gl-inet.com/firmware/ar750s/release4/openwrt-ar750s-4.3.11-0320-1710950296.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AR750S-EXT_Slate/openwrt-ar750s-4.3.11-0320-1710950296.tar
- SHA-256: `720bab77fecfa9928d50f52d102e527eb658c1c65de746533980804b59345ab7`
- Size: 16211792 bytes
- Version: 4.3.11
- Release date: 2024-03-20 23:56:40

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/720bab77fecfa992 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/720bab77fecfa992/_openwrt-ar750s-4.3.11-0320-1710950296.tar.extracted/sysupgrade-glinet_gl-ar750s-nor-nand/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
