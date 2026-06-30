# Firmware Audit: GL.iNet GL-X300B Collie / openwrt-x300b-4.5.22-0410-1744267427.bin

- Source URL: https://fw.gl-inet.com/firmware/x300b/release4/openwrt-x300b-4.5.22-0410-1744267427.bin
- Local path: known_firmware/firmware/GL.iNet_GL-X300B_Collie/openwrt-x300b-4.5.22-0410-1744267427.bin
- SHA-256: `33b6579552a0ebfcaf343c16977d4b97f864c9120ed5655aef7fbc2c7eb6fe9b`
- Size: 14025398 bytes
- Version: 4.5.22
- Release date: 2025-04-10 14:43:10

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/33b6579552a0ebfc exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/33b6579552a0ebfc/_openwrt-x300b-4.5.22-0410-1744267427.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
