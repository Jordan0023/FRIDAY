# Firmware Audit: GL.iNet GL-AXT1800 Slate AX / openwrt-axt1800-4.5.16-0321-1711033518.tar

- Source URL: https://fw.gl-inet.com/firmware/axt1800/release/openwrt-axt1800-4.5.16-0321-1711033518.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AXT1800_Slate_AX/openwrt-axt1800-4.5.16-0321-1711033518.tar
- SHA-256: `96d2631ec6f271949c1ac179ff972fb5f77c0e0b2a2f910709134114d7d2fdcf`
- Size: 48816496 bytes
- Version: 4.5.16
- Release date: 2024-03-21 23:03:45

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/96d2631ec6f27194 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/96d2631ec6f27194/_openwrt-axt1800-4.5.16-0321-1711033518.tar.extracted/sysupgrade-glinet_axt1800/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
