# Firmware Audit: GL.iNet GL-MT6000 Flint 2 / openwrt-mt6000-4.5.8-0412-1712898190.bin

- Source URL: https://fw.gl-inet.com/firmware/mt6000/release/openwrt-mt6000-4.5.8-0412-1712898190.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT6000_Flint_2/openwrt-mt6000-4.5.8-0412-1712898190.bin
- SHA-256: `2b23e7309512b1614f3557fb01db71bad7aba01dbca387f2dd809481951e7da7`
- Size: 48200832 bytes
- Version: 4.5.8
- Release date: 2024-04-12 13:00:31

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2b23e7309512b161 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/2b23e7309512b161/_openwrt-mt6000-4.5.8-0412-1712898190.bin.extracted/sysupgrade-glinet_gl-mt6000/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
