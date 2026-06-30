# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.5.0-0201-1706757612.tar

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.5.0-0201-1706757612.tar
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.5.0-0201-1706757612.tar
- SHA-256: `b23df6e13961dfa7d278789c302e0214a83a29c77f7cf14138653461e2f0cce4`
- Size: 44476570 bytes
- Version: 4.5.0
- Release date: 2024-02-01 11:17:00

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b23df6e13961dfa7 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/b23df6e13961dfa7/_openwrt-a1300-4.5.0-0201-1706757612.tar.extracted/sysupgrade-glinet_gl-a1300/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
