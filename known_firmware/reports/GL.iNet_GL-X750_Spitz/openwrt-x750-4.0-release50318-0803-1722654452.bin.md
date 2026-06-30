# Firmware Audit: GL.iNet GL-X750 Spitz / openwrt-x750-4.0-release50318-0803-1722654452.bin

- Source URL: https://fw.gl-inet.com/firmware/x750/release4/openwrt-x750-4.0-release50318-0803-1722654452.bin
- Local path: known_firmware/firmware/GL.iNet_GL-X750_Spitz/openwrt-x750-4.0-release50318-0803-1722654452.bin
- SHA-256: `1e031af73662f633d40617ed7db8414b4bd489e4cf597ce8e3889957975b4a2e`
- Size: 15009768 bytes
- Version: 4.3.18
- Release date: 2024-08-03 11:05:51

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1e031af73662f633 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/1e031af73662f633/_openwrt-x750-4.0-release50318-0803-1722654452.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
