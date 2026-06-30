# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.5.19-0826-1724680910.tar

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.5.19-0826-1724680910.tar
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.5.19-0826-1724680910.tar
- SHA-256: `e02146ca193eea8c077b773b451a089cc4ddb12aecb4d389b6b3e24ac5776d01`
- Size: 45855451 bytes
- Version: 4.5.19
- Release date: 2024-08-26 21:59:49

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e02146ca193eea8c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e02146ca193eea8c/_openwrt-a1300-4.5.19-0826-1724680910.tar.extracted/sysupgrade-glinet_gl-a1300/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
