# Firmware Audit: GL.iNet GL-SF1200 / openwrt-sf1200-3.218-0709-1720518095.bin

- Source URL: https://fw.gl-inet.com/firmware/sf1200/v4/openwrt-sf1200-3.218-0709-1720518095.bin
- Local path: known_firmware/firmware/GL.iNet_GL-SF1200/openwrt-sf1200-3.218-0709-1720518095.bin
- SHA-256: `9c278d2b45d2071a74a7800970016d23c736b69e64a8041d03398276715d0de2`
- Size: 12058912 bytes
- Version: 3.218
- Release date: 2024-07-09 17:41:35

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9c278d2b45d2071a exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/9c278d2b45d2071a/_openwrt-sf1200-3.218-0709-1720518095.bin.extracted/squashfs-root/bin/ps -> /usr/bin/busybox; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
