# Firmware Audit: GL.iNet GL-X750 Spitz / openwrt-x750-4.0-release30311-0321-1710952397.bin

- Source URL: https://fw.gl-inet.com/firmware/x750/release4/openwrt-x750-4.0-release30311-0321-1710952397.bin
- Local path: known_firmware/firmware/GL.iNet_GL-X750_Spitz/openwrt-x750-4.0-release30311-0321-1710952397.bin
- SHA-256: `08b136d116968e5c333aeefd612e248fd90e727bd66474e88180fd4bc28d1feb`
- Size: 14944074 bytes
- Version: 4.3.11
- Release date: 2024-03-21 00:31:43

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/08b136d116968e5c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/08b136d116968e5c/_openwrt-x750-4.0-release30311-0321-1710952397.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
