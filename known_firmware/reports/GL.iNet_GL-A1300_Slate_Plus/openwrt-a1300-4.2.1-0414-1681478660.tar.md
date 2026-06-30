# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.2.1-0414-1681478660.tar

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.2.1-0414-1681478660.tar
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.2.1-0414-1681478660.tar
- SHA-256: `bd3034300fc9b1ea896d322e319172335b301b4cc54df9c83c442760915864e5`
- Size: 56260154 bytes
- Version: 4.2.1
- Release date: 2023-04-14 21:22:05

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA, bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/bd3034300fc9b1ea exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/bd3034300fc9b1ea/_openwrt-a1300-4.2.1-0414-1681478660.tar.extracted/sysupgrade-glinet_gl-a1300/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
