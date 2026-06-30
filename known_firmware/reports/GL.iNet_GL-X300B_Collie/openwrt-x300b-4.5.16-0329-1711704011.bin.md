# Firmware Audit: GL.iNet GL-X300B Collie / openwrt-x300b-4.5.16-0329-1711704011.bin

- Source URL: https://fw.gl-inet.com/firmware/x300b/release4/openwrt-x300b-4.5.16-0329-1711704011.bin
- Local path: known_firmware/firmware/GL.iNet_GL-X300B_Collie/openwrt-x300b-4.5.16-0329-1711704011.bin
- SHA-256: `0bdc822549d42bc42b79c98b4da9a7f7ffcadf1e5a060052579a826e31408b93`
- Size: 13962819 bytes
- Version: 4.5.16
- Release date: 2024-03-29 17:18:32

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, bOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0bdc822549d42bc4 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/0bdc822549d42bc4/_openwrt-x300b-4.5.16-0329-1711704011.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
