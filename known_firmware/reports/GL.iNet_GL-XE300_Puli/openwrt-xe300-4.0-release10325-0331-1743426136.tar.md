# Firmware Audit: GL.iNet GL-XE300 Puli / openwrt-xe300-4.0-release10325-0331-1743426136.tar

- Source URL: https://fw.gl-inet.com/firmware/xe300/release4/openwrt-xe300-4.0-release10325-0331-1743426136.tar
- Local path: known_firmware/firmware/GL.iNet_GL-XE300_Puli/openwrt-xe300-4.0-release10325-0331-1743426136.tar
- SHA-256: `2ac15c37238ec68c7bfadc65a4cd63ad019a03378911a644135c32beec37c436`
- Size: 15883167 bytes
- Version: 4.3.25
- Release date: 2025-03-31 21:01:36

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2ac15c37238ec68c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/2ac15c37238ec68c/_openwrt-xe300-4.0-release10325-0331-1743426136.tar.extracted/sysupgrade-glinet_gl-xe300-nor-nand/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
