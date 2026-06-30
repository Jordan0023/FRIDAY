# Firmware Audit: GL.iNet GL-AXT1800 Slate AX / openwrt-axt1800-4.0.0-0603-1654254998.tar

- Source URL: https://fw.gl-inet.com/firmware/axt1800/release/openwrt-axt1800-4.0.0-0603-1654254998.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AXT1800_Slate_AX/openwrt-axt1800-4.0.0-0603-1654254998.tar
- SHA-256: `9643593d3d5d9f7c93589eee7391e8dfe053d303980470ce6572cb0e1b1dab0f`
- Size: 48917407 bytes
- Version: 4.0.0
- Release date: 2022-06-03 19:16:38

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, Boa, bOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9643593d3d5d9f7c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/9643593d3d5d9f7c/_openwrt-axt1800-4.0.0-0603-1654254998.tar.extracted/sysupgrade-glinet_axt1800/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
