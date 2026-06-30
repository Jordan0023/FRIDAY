# Firmware Audit: GL.iNet GL-AX1800 Flint / openwrt-ax1800-4.5.16-0321-1711030388.tar

- Source URL: https://fw.gl-inet.com/firmware/ax1800/v4/openwrt-ax1800-4.5.16-0321-1711030388.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AX1800_Flint/openwrt-ax1800-4.5.16-0321-1711030388.tar
- SHA-256: `abb4ff96acfff8ca40d99acb2d16e5ad85cdfc4216e6690f7c08c97dd50e4f17`
- Size: 48836974 bytes
- Version: 4.5.16
- Release date: 2024-03-21 22:11:35

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/abb4ff96acfff8ca exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/abb4ff96acfff8ca/_openwrt-ax1800-4.5.16-0321-1711030388.tar.extracted/sysupgrade-glinet_ax1800/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
