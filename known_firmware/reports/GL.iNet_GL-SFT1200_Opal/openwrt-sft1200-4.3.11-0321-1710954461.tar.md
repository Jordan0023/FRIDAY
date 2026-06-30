# Firmware Audit: GL.iNet GL-SFT1200 Opal / openwrt-sft1200-4.3.11-0321-1710954461.tar

- Source URL: https://fw.gl-inet.com/firmware/sft1200/release4/openwrt-sft1200-4.3.11-0321-1710954461.tar
- Local path: known_firmware/firmware/GL.iNet_GL-SFT1200_Opal/openwrt-sft1200-4.3.11-0321-1710954461.tar
- SHA-256: `92149b8d7d17fd507dd53ff338b1343e9bb4cf449eb0b68461219a07fbbb1eae`
- Size: 17010478 bytes
- Version: 4.3.11
- Release date: 2024-03-21 01:05:10

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/92149b8d7d17fd50 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/92149b8d7d17fd50/_openwrt-sft1200-4.3.11-0321-1710954461.tar.extracted/sysupgrade-glinet_gl-sft1200/_root.extracted/squashfs-root/bin/ps -> /usr/bin/busybox; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
