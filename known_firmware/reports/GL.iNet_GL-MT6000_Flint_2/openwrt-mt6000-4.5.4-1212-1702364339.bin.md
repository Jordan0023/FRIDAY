# Firmware Audit: GL.iNet GL-MT6000 Flint 2 / openwrt-mt6000-4.5.4-1212-1702364339.bin

- Source URL: https://fw.gl-inet.com/firmware/mt6000/release/openwrt-mt6000-4.5.4-1212-1702364339.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT6000_Flint_2/openwrt-mt6000-4.5.4-1212-1702364339.bin
- SHA-256: `0649291142da087c507f93adf04c14b075e38edef3e862bab6eb8d74e8cf8737`
- Size: 50433299 bytes
- Version: 4.5.4
- Release date: 2023-12-12 15:09:47

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `sshd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0649291142da087c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/0649291142da087c/_openwrt-mt6000-4.5.4-1212-1702364339.bin.extracted/sysupgrade-glinet_gl-mt6000/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
