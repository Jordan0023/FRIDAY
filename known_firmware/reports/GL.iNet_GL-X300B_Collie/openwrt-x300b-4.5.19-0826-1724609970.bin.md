# Firmware Audit: GL.iNet GL-X300B Collie / openwrt-x300b-4.5.19-0826-1724609970.bin

- Source URL: https://fw.gl-inet.com/firmware/x300b/release4/openwrt-x300b-4.5.19-0826-1724609970.bin
- Local path: known_firmware/firmware/GL.iNet_GL-X300B_Collie/openwrt-x300b-4.5.19-0826-1724609970.bin
- SHA-256: `97febfa2bbebb81c10d97cd2862ee74438ea74695408251cf8e94c8753e697ee`
- Size: 13959935 bytes
- Version: 4.5.19
- Release date: 2024-08-26 02:17:51

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, bOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/97febfa2bbebb81c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/97febfa2bbebb81c/_openwrt-x300b-4.5.19-0826-1724609970.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
