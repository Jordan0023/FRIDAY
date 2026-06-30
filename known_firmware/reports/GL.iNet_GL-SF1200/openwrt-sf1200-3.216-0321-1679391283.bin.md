# Firmware Audit: GL.iNet GL-SF1200 / openwrt-sf1200-3.216-0321-1679391283.bin

- Source URL: https://fw.gl-inet.com/firmware/sf1200/release/openwrt-sf1200-3.216-0321-1679391283.bin
- Local path: known_firmware/firmware/GL.iNet_GL-SF1200/openwrt-sf1200-3.216-0321-1679391283.bin
- SHA-256: `a7cadbdd0e735a11fa8d998e8b264afe373bebf8f55a8eb8cd891381252b2f56`
- Size: 12058912 bytes
- Version: 3.216
- Release date: 2023-03-21 17:34:43

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a7cadbdd0e735a11 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/a7cadbdd0e735a11/_openwrt-sf1200-3.216-0321-1679391283.bin.extracted/squashfs-root/bin/ps -> /usr/bin/busybox; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
