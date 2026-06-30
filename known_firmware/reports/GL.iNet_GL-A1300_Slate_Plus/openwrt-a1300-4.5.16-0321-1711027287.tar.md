# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.5.16-0321-1711027287.tar

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.5.16-0321-1711027287.tar
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.5.16-0321-1711027287.tar
- SHA-256: `b288fb6a6940aa038537c35a5cd76eb6b04bd9b9be94d06952b1601064d2fb9c`
- Size: 45836647 bytes
- Version: 4.5.16
- Release date: 2024-03-21 21:19:35

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b288fb6a6940aa03 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/b288fb6a6940aa03/_openwrt-a1300-4.5.16-0321-1711027287.tar.extracted/sysupgrade-glinet_gl-a1300/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
