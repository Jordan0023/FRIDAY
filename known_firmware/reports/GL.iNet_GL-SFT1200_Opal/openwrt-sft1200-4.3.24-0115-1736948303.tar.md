# Firmware Audit: GL.iNet GL-SFT1200 Opal / openwrt-sft1200-4.3.24-0115-1736948303.tar

- Source URL: https://fw.gl-inet.com/firmware/sft1200/release4/openwrt-sft1200-4.3.24-0115-1736948303.tar
- Local path: known_firmware/firmware/GL.iNet_GL-SFT1200_Opal/openwrt-sft1200-4.3.24-0115-1736948303.tar
- SHA-256: `38ba1d9cab5ff812522ddc1cb74486c763783a0d1bd50a874b3ee4df9f1bc23e`
- Size: 17193829 bytes
- Version: 4.3.24
- Release date: 2025-01-15 21:27:24

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/38ba1d9cab5ff812 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/38ba1d9cab5ff812/_openwrt-sft1200-4.3.24-0115-1736948303.tar.extracted/sysupgrade-glinet_gl-sft1200/_root.extracted/squashfs-root/bin/ps -> /usr/bin/busybox; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
