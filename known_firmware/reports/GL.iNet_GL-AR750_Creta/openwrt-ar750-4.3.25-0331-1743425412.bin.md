# Firmware Audit: GL.iNet GL-AR750 Creta / openwrt-ar750-4.3.25-0331-1743425412.bin

- Source URL: https://fw.gl-inet.com/firmware/ar750/release4/openwrt-ar750-4.3.25-0331-1743425412.bin
- Local path: known_firmware/firmware/GL.iNet_GL-AR750_Creta/openwrt-ar750-4.3.25-0331-1743425412.bin
- SHA-256: `42d36282c14fee281419daa609e35e7d26246a52886981a9d10f082eda67aa33`
- Size: 14877585 bytes
- Version: 4.3.25
- Release date: 2025-03-31 20:48:49

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/42d36282c14fee28 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/42d36282c14fee28/_openwrt-ar750-4.3.25-0331-1743425412.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
