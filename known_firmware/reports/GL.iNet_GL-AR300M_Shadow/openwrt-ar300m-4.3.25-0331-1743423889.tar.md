# Firmware Audit: GL.iNet GL-AR300M Shadow / openwrt-ar300m-4.3.25-0331-1743423889.tar

- Source URL: https://fw.gl-inet.com/firmware/ar300m/nand/release4/openwrt-ar300m-4.3.25-0331-1743423889.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AR300M_Shadow/openwrt-ar300m-4.3.25-0331-1743423889.tar
- SHA-256: `30d565360cedebd12bfde99bfc259b230c87768bc3da632c2793ac7bae3b0eb4`
- Size: 15422355 bytes
- Version: 4.3.25
- Release date: 2025-03-31 20:23:09

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, Boa, bOA, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/30d565360cedebd1 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/30d565360cedebd1/_openwrt-ar300m-4.3.25-0331-1743423889.tar.extracted/sysupgrade-glinet_gl-ar300m-nand/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
