# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.5.22-0408-1744104085.tar

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.5.22-0408-1744104085.tar
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.5.22-0408-1744104085.tar
- SHA-256: `ef25c2803d1b0e727748c3aeeb5c4aa950066fedfa18cb171ca3f4f0180cf5bd`
- Size: 45865618 bytes
- Version: 4.5.22
- Release date: 2025-04-08 17:20:43

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/ef25c2803d1b0e72 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/ef25c2803d1b0e72/_openwrt-a1300-4.5.22-0408-1744104085.tar.extracted/sysupgrade-glinet_gl-a1300/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
