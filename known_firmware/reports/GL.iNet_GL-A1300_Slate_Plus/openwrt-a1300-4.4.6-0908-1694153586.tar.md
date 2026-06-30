# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.4.6-0908-1694153586.tar

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.4.6-0908-1694153586.tar
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.4.6-0908-1694153586.tar
- SHA-256: `6f39cfd104ef31d2b6406d10c5b921e5ed963dd7c98ef10ec7756a2ad99034b9`
- Size: 56342377 bytes
- Version: 4.4.6
- Release date: 2023-09-08 14:11:04

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, bOA, bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6f39cfd104ef31d2 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/6f39cfd104ef31d2/_openwrt-a1300-4.4.6-0908-1694153586.tar.extracted/sysupgrade-glinet_gl-a1300/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
