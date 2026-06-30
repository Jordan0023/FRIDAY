# Firmware Audit: GL.iNet GL-X750 Spitz / openwrt-x750-4.0-release10325-0331-1743426151.bin

- Source URL: https://fw.gl-inet.com/firmware/x750/release4/openwrt-x750-4.0-release10325-0331-1743426151.bin
- Local path: known_firmware/firmware/GL.iNet_GL-X750_Spitz/openwrt-x750-4.0-release10325-0331-1743426151.bin
- SHA-256: `c6f0d845474d3d2f06928f94c9dce5f42f16e002901ce296aba79f9d4564ac97`
- Size: 15008661 bytes
- Version: 4.3.25
- Release date: 2025-03-31 21:01:57

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c6f0d845474d3d2f exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/c6f0d845474d3d2f/_openwrt-x750-4.0-release10325-0331-1743426151.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
