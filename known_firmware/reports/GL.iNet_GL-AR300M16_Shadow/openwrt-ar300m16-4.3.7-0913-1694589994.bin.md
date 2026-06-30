# Firmware Audit: GL.iNet GL-AR300M16 Shadow / openwrt-ar300m16-4.3.7-0913-1694589994.bin

- Source URL: https://fw.gl-inet.com/firmware/ar300m/release4/openwrt-ar300m16-4.3.7-0913-1694589994.bin
- Local path: known_firmware/firmware/GL.iNet_GL-AR300M16_Shadow/openwrt-ar300m16-4.3.7-0913-1694589994.bin
- SHA-256: `e8ee30e99d6a23c7c2aef95e83cfe94c1785cde35b076519285f3f3bdb21b663`
- Size: 15468873 bytes
- Version: 4.3.7
- Release date: 2023-09-13 15:25:26

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e8ee30e99d6a23c7 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e8ee30e99d6a23c7/_openwrt-ar300m16-4.3.7-0913-1694589994.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
