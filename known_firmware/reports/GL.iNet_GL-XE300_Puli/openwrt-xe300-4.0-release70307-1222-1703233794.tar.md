# Firmware Audit: GL.iNet GL-XE300 Puli / openwrt-xe300-4.0-release70307-1222-1703233794.tar

- Source URL: https://fw.gl-inet.com/firmware/xe300/release4/openwrt-xe300-4.0-release70307-1222-1703233794.tar
- Local path: known_firmware/firmware/GL.iNet_GL-XE300_Puli/openwrt-xe300-4.0-release70307-1222-1703233794.tar
- SHA-256: `e4a6e145a336bd45f60fff7ef7d7200bd01c34e11230f997d8165cfb85026524`
- Size: 16726103 bytes
- Version: 4.3.7
- Release date: 2023-12-22 16:28:41

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e4a6e145a336bd45 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e4a6e145a336bd45/_openwrt-xe300-4.0-release70307-1222-1703233794.tar.extracted/sysupgrade-glinet_gl-xe300-nor-nand/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
