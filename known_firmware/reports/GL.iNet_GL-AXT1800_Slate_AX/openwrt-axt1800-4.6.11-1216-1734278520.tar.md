# Firmware Audit: GL.iNet GL-AXT1800 Slate AX / openwrt-axt1800-4.6.11-1216-1734278520.tar

- Source URL: https://fw.gl-inet.com/firmware/axt1800/release/openwrt-axt1800-4.6.11-1216-1734278520.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AXT1800_Slate_AX/openwrt-axt1800-4.6.11-1216-1734278520.tar
- SHA-256: `fc9bf38d930e7281287b89525dda4c790be093e7adaba3b44316ed2e73150b98`
- Size: 47063920 bytes
- Version: 4.6.11
- Release date: 2024-12-15 23:26:32

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, Boa, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/fc9bf38d930e7281 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/fc9bf38d930e7281/_openwrt-axt1800-4.6.11-1216-1734278520.tar.extracted/sysupgrade-glinet_axt1800/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
