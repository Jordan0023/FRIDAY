# Firmware Audit: GL.iNet GL-E750/GL-E750V2 Mudi / openwrt-e750-4.0-release30319-0906-1725586285.tar

- Source URL: https://fw.gl-inet.com/firmware/e750/release4/openwrt-e750-4.0-release30319-0906-1725586285.tar
- Local path: known_firmware/firmware/GL.iNet_GL-E750_GL-E750V2_Mudi/openwrt-e750-4.0-release30319-0906-1725586285.tar
- SHA-256: `1b5a5b785335e66e5c4f731734d79d8765145bf4fb807582fcac25cccb250d9c`
- Size: 21597333 bytes
- Version: 4.3.19
- Release date: 2024-09-06 09:29:08

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1b5a5b785335e66e exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/1b5a5b785335e66e/_openwrt-e750-4.0-release30319-0906-1725586285.tar.extracted/sysupgrade-glinet_gl-e750/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
