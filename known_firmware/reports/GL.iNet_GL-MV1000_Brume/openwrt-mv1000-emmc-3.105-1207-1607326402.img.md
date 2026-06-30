# Firmware Audit: GL.iNet GL-MV1000 Brume / openwrt-mv1000-emmc-3.105-1207-1607326402.img

- Source URL: https://fw.gl-inet.com/firmware/mv1000/v1/openwrt-mv1000-emmc-3.105-1207-1607326402.img
- Local path: known_firmware/firmware/GL.iNet_GL-MV1000_Brume/openwrt-mv1000-emmc-3.105-1207-1607326402.img
- SHA-256: `3ce761f2904b6061b57adfe9287501830bd7756220f663f906051866f6581b23`
- Size: 41085043 bytes
- Version: 3.105
- Release date: 2020-12-07 15:33:22

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, Boa, bOa, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3ce761f2904b6061 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/3ce761f2904b6061/_openwrt-mv1000-emmc-3.105-1207-1607326402.img.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
