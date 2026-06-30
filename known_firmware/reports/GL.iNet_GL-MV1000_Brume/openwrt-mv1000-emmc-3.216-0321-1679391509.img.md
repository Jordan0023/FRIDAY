# Firmware Audit: GL.iNet GL-MV1000 Brume / openwrt-mv1000-emmc-3.216-0321-1679391509.img

- Source URL: https://fw.gl-inet.com/firmware/mv1000/v1/openwrt-mv1000-emmc-3.216-0321-1679391509.img
- Local path: known_firmware/firmware/GL.iNet_GL-MV1000_Brume/openwrt-mv1000-emmc-3.216-0321-1679391509.img
- SHA-256: `9fa874dc24338798fddb48665ac66c53af731989d2499a099fb357d515116e11`
- Size: 43415607 bytes
- Version: 3.216
- Release date: 2023-03-21 17:38:29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9fa874dc24338798 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/9fa874dc24338798/_openwrt-mv1000-emmc-3.216-0321-1679391509.img.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
