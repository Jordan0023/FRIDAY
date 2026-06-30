# Firmware Audit: GL.iNet GL-AR750S-EXT Slate / openwrt-ar750s-4.3.7-0913-1694591157.tar

- Source URL: https://fw.gl-inet.com/firmware/ar750s/release4/openwrt-ar750s-4.3.7-0913-1694591157.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AR750S-EXT_Slate/openwrt-ar750s-4.3.7-0913-1694591157.tar
- SHA-256: `176236202c7d01d24ef5357418afc817bfb183c963f27167ee56d805f7e02888`
- Size: 16621890 bytes
- Version: 4.3.7
- Release date: 2023-09-13 15:44:49

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/176236202c7d01d2 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/176236202c7d01d2/_openwrt-ar750s-4.3.7-0913-1694591157.tar.extracted/sysupgrade-glinet_gl-ar750s-nor-nand/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
