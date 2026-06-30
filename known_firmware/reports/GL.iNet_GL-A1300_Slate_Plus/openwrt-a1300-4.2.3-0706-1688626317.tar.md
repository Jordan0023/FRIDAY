# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.2.3-0706-1688626317.tar

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.2.3-0706-1688626317.tar
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.2.3-0706-1688626317.tar
- SHA-256: `b5076312d0e8aa9e9aabba02ea475916ac12ff2564927ab1d8354dd7e8270c6f`
- Size: 56260832 bytes
- Version: 4.2.3
- Release date: 2023-07-06 14:49:43

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA, bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b5076312d0e8aa9e exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/b5076312d0e8aa9e/_openwrt-a1300-4.2.3-0706-1688626317.tar.extracted/sysupgrade-glinet_gl-a1300/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
