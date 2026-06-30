# Firmware Audit: GL.iNet GL-MT3000 Beryl AX / openwrt-mt3000-4.6.8-1014-1728909330.tar

- Source URL: https://fw.gl-inet.com/firmware/mt3000/release/openwrt-mt3000-4.6.8-1014-1728909330.tar
- Local path: known_firmware/firmware/GL.iNet_GL-MT3000_Beryl_AX/openwrt-mt3000-4.6.8-1014-1728909330.tar
- SHA-256: `ecb830e1b112b8910fca1aac17d9060d625b5d057d4037586f349abd5a33afd6`
- Size: 47894039 bytes
- Version: 4.6.8
- Release date: 2024-10-14 19:57:13

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ecb830e1b112b891 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/ecb830e1b112b891/_openwrt-mt3000-4.6.8-1014-1728909330.tar.extracted/sysupgrade-glinet_gl-mt3000/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
