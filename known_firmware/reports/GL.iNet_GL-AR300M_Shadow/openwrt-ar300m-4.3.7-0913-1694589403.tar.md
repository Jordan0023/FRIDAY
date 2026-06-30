# Firmware Audit: GL.iNet GL-AR300M Shadow / openwrt-ar300m-4.3.7-0913-1694589403.tar

- Source URL: https://fw.gl-inet.com/firmware/ar300m/nand/release4/openwrt-ar300m-4.3.7-0913-1694589403.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AR300M_Shadow/openwrt-ar300m-4.3.7-0913-1694589403.tar
- SHA-256: `c2991461b836b2dc61b72fbab04fc47b24c7c4590ee3b20505c55b4639931d3a`
- Size: 15454522 bytes
- Version: 4.3.7
- Release date: 2023-09-13 15:15:37

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c2991461b836b2dc exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/c2991461b836b2dc/_openwrt-ar300m-4.3.7-0913-1694589403.tar.extracted/sysupgrade-glinet_gl-ar300m-nand/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
