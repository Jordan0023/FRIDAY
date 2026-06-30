# Firmware Audit: GL.iNet GL-MT6000 Flint 2 / openwrt-mt6000-4.5.3-1201-1701400128.bin

- Source URL: https://fw.gl-inet.com/firmware/mt6000/release/openwrt-mt6000-4.5.3-1201-1701400128.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT6000_Flint_2/openwrt-mt6000-4.5.3-1201-1701400128.bin
- SHA-256: `44fd56b1fc71d75a1444806f22d845c9bd825211fd80606830735cbcaa193528`
- Size: 50402305 bytes
- Version: 4.5.3
- Release date: 2023-12-01 12:17:34

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

- binwalk -eM --directory known_firmware/extracted/44fd56b1fc71d75a exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/44fd56b1fc71d75a/_openwrt-mt6000-4.5.3-1201-1701400128.bin.extracted/sysupgrade-glinet_gl-mt6000/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
