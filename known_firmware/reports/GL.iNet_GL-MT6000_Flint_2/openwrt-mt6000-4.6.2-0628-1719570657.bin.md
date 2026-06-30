# Firmware Audit: GL.iNet GL-MT6000 Flint 2 / openwrt-mt6000-4.6.2-0628-1719570657.bin

- Source URL: https://fw.gl-inet.com/firmware/mt6000/release/openwrt-mt6000-4.6.2-0628-1719570657.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT6000_Flint_2/openwrt-mt6000-4.6.2-0628-1719570657.bin
- SHA-256: `e2d6f1ce8c24f1d8cc25753e602f5f42dc55d5fb7bb14361346985df7f74ace5`
- Size: 49607234 bytes
- Version: 4.6.2
- Release date: 2024-06-28 17:59:09

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, bOA, bOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e2d6f1ce8c24f1d8 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e2d6f1ce8c24f1d8/_openwrt-mt6000-4.6.2-0628-1719570657.bin.extracted/sysupgrade-glinet_gl-mt6000/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
