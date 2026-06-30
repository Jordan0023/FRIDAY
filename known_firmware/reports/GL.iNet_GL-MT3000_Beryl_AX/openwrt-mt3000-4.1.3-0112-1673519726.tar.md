# Firmware Audit: GL.iNet GL-MT3000 Beryl AX / openwrt-mt3000-4.1.3-0112-1673519726.tar

- Source URL: https://fw.gl-inet.com/firmware/mt3000/release/openwrt-mt3000-4.1.3-0112-1673519726.tar
- Local path: known_firmware/firmware/GL.iNet_GL-MT3000_Beryl_AX/openwrt-mt3000-4.1.3-0112-1673519726.tar
- SHA-256: `9dada4947fcaf640b4ffde775019d929d2bb5c6d31e77138c463827d493e6492`
- Size: 52869907 bytes
- Version: 4.1.3
- Release date: 2023-01-12 18:51:32

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, bOA, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9dada4947fcaf640 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/9dada4947fcaf640/_openwrt-mt3000-4.1.3-0112-1673519726.tar.extracted/sysupgrade-glinet_gl-mt3000/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
