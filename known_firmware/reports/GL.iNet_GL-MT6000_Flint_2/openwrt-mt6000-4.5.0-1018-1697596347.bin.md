# Firmware Audit: GL.iNet GL-MT6000 Flint 2 / openwrt-mt6000-4.5.0-1018-1697596347.bin

- Source URL: https://fw.gl-inet.com/firmware/mt6000/release/openwrt-mt6000-4.5.0-1018-1697596347.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT6000_Flint_2/openwrt-mt6000-4.5.0-1018-1697596347.bin
- SHA-256: `8e0fe622394a20eef9d7dc352caa1db448f91b5519fa57e88c73c58976011e7d`
- Size: 51169888 bytes
- Version: 4.5.0
- Release date: 2023-10-17 20:10:22

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `sshd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA, Boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/8e0fe622394a20ee exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/8e0fe622394a20ee/_openwrt-mt6000-4.5.0-1018-1697596347.bin.extracted/sysupgrade-glinet_gl-mt6000/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
