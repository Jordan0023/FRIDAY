# Firmware Audit: GL.iNet GL-X300B Collie / openwrt-x300b-3.215-0921-1663732420.bin

- Source URL: https://fw.gl-inet.com/firmware/x300b/release/openwrt-x300b-3.215-0921-1663732420.bin
- Local path: known_firmware/firmware/GL.iNet_GL-X300B_Collie/openwrt-x300b-3.215-0921-1663732420.bin
- SHA-256: `cf1a81ddab5fbeb874cb084af9c8e358bdc9d6dedb410c3270e9fcace8d04b2b`
- Size: 12058948 bytes
- Version: 3.215
- Release date: 2022-09-21 11:53:40

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/cf1a81ddab5fbeb8 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/cf1a81ddab5fbeb8/_openwrt-x300b-3.215-0921-1663732420.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
