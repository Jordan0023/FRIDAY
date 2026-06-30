# Firmware Audit: GL.iNet GL-X300B Collie / openwrt-x300b-3.217-0508-1683513926.bin

- Source URL: https://fw.gl-inet.com/firmware/x300b/release/openwrt-x300b-3.217-0508-1683513926.bin
- Local path: known_firmware/firmware/GL.iNet_GL-X300B_Collie/openwrt-x300b-3.217-0508-1683513926.bin
- SHA-256: `44621110f771982c837baa07bb801dbc9e0d92527b9afe809bf136858f58bf27`
- Size: 12058948 bytes
- Version: 3.217
- Release date: 2023-05-08 10:45:26

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/44621110f771982c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/44621110f771982c/_openwrt-x300b-3.217-0508-1683513926.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
