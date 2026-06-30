# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.1.0-1105-1667640857.tar

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.1.0-1105-1667640857.tar
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.1.0-1105-1667640857.tar
- SHA-256: `42df68a8213957694158c243566ee6d57c61be1b31d2126d9dfb54fbe36af75e`
- Size: 48745448 bytes
- Version: 4.1.0
- Release date: 2022-11-05 17:34:17

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, bOA, bOa, boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/42df68a821395769 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/42df68a821395769/_openwrt-a1300-4.1.0-1105-1667640857.tar.extracted/sysupgrade-glinet_gl-a1300/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
