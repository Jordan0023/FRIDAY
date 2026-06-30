# Firmware Audit: GL.iNet GL-MT2500/GL-MT2500A Brume 2 / openwrt-mt2500-4.6.8-1017-1729169844.bin

- Source URL: https://fw.gl-inet.com/firmware/mt2500/release/openwrt-mt2500-4.6.8-1017-1729169844.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT2500_GL-MT2500A_Brume_2/openwrt-mt2500-4.6.8-1017-1729169844.bin
- SHA-256: `7d28e9f3520412a59842d56d7113ae856a7addd5d7708cd718c1c71e34fc43e6`
- Size: 45426164 bytes
- Version: 4.6.8
- Release date: 2024-10-17 20:25:41

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7d28e9f3520412a5 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/7d28e9f3520412a5/_openwrt-mt2500-4.6.8-1017-1729169844.bin.extracted/sysupgrade-glinet_gl-mt2500/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
