# Firmware Audit: GL.iNet GL-SFT1200 Opal / openwrt-sft1200-3.215-0921-1663732145.tar

- Source URL: https://fw.gl-inet.com/firmware/sft1200/release/openwrt-sft1200-3.215-0921-1663732145.tar
- Local path: known_firmware/firmware/GL.iNet_GL-SFT1200_Opal/openwrt-sft1200-3.215-0921-1663732145.tar
- SHA-256: `a071d82e4988967983a46f2c6429438eef30d80e9746bca9ef7075d69fef16de`
- Size: 16537886 bytes
- Version: 3.215
- Release date: 2022-09-21 11:49:05

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a071d82e49889679 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/a071d82e49889679/_openwrt-sft1200-3.215-0921-1663732145.tar.extracted/sysupgrade-glinet_gl-sft1200/_root.extracted/squashfs-root-0/bin/ps -> /usr/bin/busybox; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
