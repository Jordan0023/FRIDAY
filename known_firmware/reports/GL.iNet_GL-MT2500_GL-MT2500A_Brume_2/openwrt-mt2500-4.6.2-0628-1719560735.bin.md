# Firmware Audit: GL.iNet GL-MT2500/GL-MT2500A Brume 2 / openwrt-mt2500-4.6.2-0628-1719560735.bin

- Source URL: https://fw.gl-inet.com/firmware/mt2500/release/openwrt-mt2500-4.6.2-0628-1719560735.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT2500_GL-MT2500A_Brume_2/openwrt-mt2500-4.6.2-0628-1719560735.bin
- SHA-256: `c9ad8ac3fa189cfd4e20384adb54c5b0994606cb9bb3a30b2099de7742c8328a`
- Size: 45408857 bytes
- Version: 4.6.2
- Release date: 2024-06-28 15:14:30

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, bOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c9ad8ac3fa189cfd exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/c9ad8ac3fa189cfd/_openwrt-mt2500-4.6.2-0628-1719560735.bin.extracted/sysupgrade-glinet_gl-mt2500/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
