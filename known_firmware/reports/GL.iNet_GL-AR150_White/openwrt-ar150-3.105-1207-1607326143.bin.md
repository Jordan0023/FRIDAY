# Firmware Audit: GL.iNet GL-AR150 White / openwrt-ar150-3.105-1207-1607326143.bin

- Source URL: https://fw.gl-inet.com/firmware/ar150/v1/openwrt-ar150-3.105-1207-1607326143.bin
- Local path: known_firmware/firmware/GL.iNet_GL-AR150_White/openwrt-ar150-3.105-1207-1607326143.bin
- SHA-256: `f5223eeec009777b9335649d8351aead08546f38b3933c16913e2cb718ff0169`
- Size: 13172740 bytes
- Version: 3.105
- Release date: 2020-12-07 15:29:03

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f5223eeec009777b exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/f5223eeec009777b/_openwrt-ar150-3.105-1207-1607326143.bin.extracted/squashfs-root/bin/ps -> /usr/bin/busybox; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
