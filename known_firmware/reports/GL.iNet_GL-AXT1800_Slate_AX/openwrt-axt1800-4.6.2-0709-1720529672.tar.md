# Firmware Audit: GL.iNet GL-AXT1800 Slate AX / openwrt-axt1800-4.6.2-0709-1720529672.tar

- Source URL: https://fw.gl-inet.com/firmware/axt1800/release/openwrt-axt1800-4.6.2-0709-1720529672.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AXT1800_Slate_AX/openwrt-axt1800-4.6.2-0709-1720529672.tar
- SHA-256: `a3766797f96c0982bb0f9673be02f9cac640524d2e737019bf6c7865d7c37d9a`
- Size: 46965331 bytes
- Version: 4.6.2
- Release date: 2024-07-09 20:18:22

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, Boa, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a3766797f96c0982 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/a3766797f96c0982/_openwrt-axt1800-4.6.2-0709-1720529672.tar.extracted/sysupgrade-glinet_axt1800/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
