# Firmware Audit: GL.iNet GL-AR300M16 Shadow / openwrt-ar300m16-4.3.10-0202-1706854731.bin

- Source URL: https://fw.gl-inet.com/firmware/ar300m/release4/openwrt-ar300m16-4.3.10-0202-1706854731.bin
- Local path: known_firmware/firmware/GL.iNet_GL-AR300M16_Shadow/openwrt-ar300m16-4.3.10-0202-1706854731.bin
- SHA-256: `cdde3efa4b851c7b84b5b337d800e5dadcd7d9809cca0096e2fc2074329f19e3`
- Size: 15534589 bytes
- Version: 4.3.10
- Release date: 2024-02-02 14:17:54

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/cdde3efa4b851c7b exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/cdde3efa4b851c7b/_openwrt-ar300m16-4.3.10-0202-1706854731.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
