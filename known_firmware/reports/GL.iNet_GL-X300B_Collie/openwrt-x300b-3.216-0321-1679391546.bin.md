# Firmware Audit: GL.iNet GL-X300B Collie / openwrt-x300b-3.216-0321-1679391546.bin

- Source URL: https://fw.gl-inet.com/firmware/x300b/release/openwrt-x300b-3.216-0321-1679391546.bin
- Local path: known_firmware/firmware/GL.iNet_GL-X300B_Collie/openwrt-x300b-3.216-0321-1679391546.bin
- SHA-256: `2068a20426a5267a166db4b31114f0c0db884866970bb2665b0eb87e52f3b4b6`
- Size: 12058948 bytes
- Version: 3.216
- Release date: 2023-03-21 17:39:06

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2068a20426a5267a exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/2068a20426a5267a/_openwrt-x300b-3.216-0321-1679391546.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
