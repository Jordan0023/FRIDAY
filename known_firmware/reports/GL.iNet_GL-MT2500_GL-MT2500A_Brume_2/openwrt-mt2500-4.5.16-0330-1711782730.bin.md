# Firmware Audit: GL.iNet GL-MT2500/GL-MT2500A Brume 2 / openwrt-mt2500-4.5.16-0330-1711782730.bin

- Source URL: https://fw.gl-inet.com/firmware/mt2500/release/openwrt-mt2500-4.5.16-0330-1711782730.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT2500_GL-MT2500A_Brume_2/openwrt-mt2500-4.5.16-0330-1711782730.bin
- SHA-256: `6254250bbe3c4cf33c61a7de683e6a4e1db6bdbb1b8146144aed46744077e6dc`
- Size: 46585390 bytes
- Version: 4.5.16
- Release date: 2024-03-30 15:11:32

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6254250bbe3c4cf3 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/6254250bbe3c4cf3/_openwrt-mt2500-4.5.16-0330-1711782730.bin.extracted/sysupgrade-glinet_gl-mt2500/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
