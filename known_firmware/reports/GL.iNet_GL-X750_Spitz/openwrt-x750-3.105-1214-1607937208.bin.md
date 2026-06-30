# Firmware Audit: GL.iNet GL-X750 Spitz / openwrt-x750-3.105-1214-1607937208.bin

- Source URL: https://fw.gl-inet.com/firmware/x750/release/openwrt-x750-3.105-1214-1607937208.bin
- Local path: known_firmware/firmware/GL.iNet_GL-X750_Spitz/openwrt-x750-3.105-1214-1607937208.bin
- SHA-256: `56641430e71795d9e2d80e7736478d4a5d2a121a4a351cdec3888bbb97a5015d`
- Size: 13566124 bytes
- Version: 3.105
- Release date: 2020-12-14 17:13:28

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/56641430e71795d9 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/56641430e71795d9/_openwrt-x750-3.105-1214-1607937208.bin.extracted/squashfs-root/bin/ps -> /usr/bin/busybox; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
