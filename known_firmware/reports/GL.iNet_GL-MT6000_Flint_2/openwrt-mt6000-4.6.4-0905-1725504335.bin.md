# Firmware Audit: GL.iNet GL-MT6000 Flint 2 / openwrt-mt6000-4.6.4-0905-1725504335.bin

- Source URL: https://fw.gl-inet.com/firmware/mt6000/release/openwrt-mt6000-4.6.4-0905-1725504335.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT6000_Flint_2/openwrt-mt6000-4.6.4-0905-1725504335.bin
- SHA-256: `f9bf50d5e2b3fbabc96353656970b825d3a95b613887db8b938809a18728dcd0`
- Size: 49698795 bytes
- Version: 4.6.4
- Release date: 2024-09-05 10:13:35

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f9bf50d5e2b3fbab exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/f9bf50d5e2b3fbab/_openwrt-mt6000-4.6.4-0905-1725504335.bin.extracted/sysupgrade-glinet_gl-mt6000/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
