# Firmware Audit: GL.iNet GL-SFT1200 Opal / openwrt-sft1200-4.3.21-1016-1729054354.tar

- Source URL: https://fw.gl-inet.com/firmware/sft1200/release4/openwrt-sft1200-4.3.21-1016-1729054354.tar
- Local path: known_firmware/firmware/GL.iNet_GL-SFT1200_Opal/openwrt-sft1200-4.3.21-1016-1729054354.tar
- SHA-256: `e4eabfb15eb958aa46e7d6c46c9e4a9edb6386c83fb85e44ee69e0179ec04715`
- Size: 17205024 bytes
- Version: 4.3.21
- Release date: 2024-10-16 12:32:41

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e4eabfb15eb958aa exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e4eabfb15eb958aa/_openwrt-sft1200-4.3.21-1016-1729054354.tar.extracted/sysupgrade-glinet_gl-sft1200/_root.extracted/squashfs-root/bin/ps -> /usr/bin/busybox; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
