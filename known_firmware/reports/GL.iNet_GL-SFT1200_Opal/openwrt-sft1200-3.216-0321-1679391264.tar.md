# Firmware Audit: GL.iNet GL-SFT1200 Opal / openwrt-sft1200-3.216-0321-1679391264.tar

- Source URL: https://fw.gl-inet.com/firmware/sft1200/release/openwrt-sft1200-3.216-0321-1679391264.tar
- Local path: known_firmware/firmware/GL.iNet_GL-SFT1200_Opal/openwrt-sft1200-3.216-0321-1679391264.tar
- SHA-256: `5a88a3f715a3457c26e8ea43dac1e782e3e83310e04839d0ed5d28944813816e`
- Size: 16537886 bytes
- Version: 3.216
- Release date: 2023-03-21 17:34:24

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5a88a3f715a3457c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/5a88a3f715a3457c/_openwrt-sft1200-3.216-0321-1679391264.tar.extracted/sysupgrade-glinet_gl-sft1200/_root.extracted/squashfs-root-0/bin/ps -> /usr/bin/busybox; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
