# Firmware Audit: GL.iNet GL-SFT1200 Opal / openwrt-sft1200-4.3.18-0726-1721984376.tar

- Source URL: https://fw.gl-inet.com/firmware/sft1200/release4/openwrt-sft1200-4.3.18-0726-1721984376.tar
- Local path: known_firmware/firmware/GL.iNet_GL-SFT1200_Opal/openwrt-sft1200-4.3.18-0726-1721984376.tar
- SHA-256: `f7ddbddf679c808b7805627615bca7cae704032f119bcbadde39a648e89ccac5`
- Size: 17081843 bytes
- Version: 4.3.18
- Release date: 2024-07-26 16:39:43

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f7ddbddf679c808b exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/f7ddbddf679c808b/_openwrt-sft1200-4.3.18-0726-1721984376.tar.extracted/sysupgrade-glinet_gl-sft1200/_root.extracted/squashfs-root-0/bin/ps -> /usr/bin/busybox; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
