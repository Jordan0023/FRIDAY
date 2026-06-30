# Firmware Audit: GL.iNet GL-X750 Spitz / openwrt-x750-3.215-0921-1663731987.bin

- Source URL: https://fw.gl-inet.com/firmware/x750/release/openwrt-x750-3.215-0921-1663731987.bin
- Local path: known_firmware/firmware/GL.iNet_GL-X750_Spitz/openwrt-x750-3.215-0921-1663731987.bin
- SHA-256: `25f4d2ef09783785d56cccd5fe66037ac91c0edeb287f9beba580c1e8fa6efc0`
- Size: 13107520 bytes
- Version: 3.215
- Release date: 2022-09-21 11:46:27

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, bOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/25f4d2ef09783785 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/25f4d2ef09783785/_openwrt-x750-3.215-0921-1663731987.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
