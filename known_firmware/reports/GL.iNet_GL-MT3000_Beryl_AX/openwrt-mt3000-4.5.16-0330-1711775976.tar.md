# Firmware Audit: GL.iNet GL-MT3000 Beryl AX / openwrt-mt3000-4.5.16-0330-1711775976.tar

- Source URL: https://fw.gl-inet.com/firmware/mt3000/release/openwrt-mt3000-4.5.16-0330-1711775976.tar
- Local path: known_firmware/firmware/GL.iNet_GL-MT3000_Beryl_AX/openwrt-mt3000-4.5.16-0330-1711775976.tar
- SHA-256: `cf2ceedb3f54f2963fb23f73712a21ef3f93a3a2f889ba66a7e9762b3839b8ee`
- Size: 49677871 bytes
- Version: 4.5.16
- Release date: 2024-03-30 13:17:15

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, bOA, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/cf2ceedb3f54f296 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/cf2ceedb3f54f296/_openwrt-mt3000-4.5.16-0330-1711775976.tar.extracted/sysupgrade-glinet_gl-mt3000/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
