# Firmware Audit: GL.iNet GL-MV1000 Brume / openwrt-mv1000-emmc-3.218-0727-1722069119.img

- Source URL: https://fw.gl-inet.com/firmware/mv1000/v4/openwrt-mv1000-emmc-3.218-0727-1722069119.img
- Local path: known_firmware/firmware/GL.iNet_GL-MV1000_Brume/openwrt-mv1000-emmc-3.218-0727-1722069119.img
- SHA-256: `252f9e39237788618b9723920eb33502201de4719e2fafdb4f357aea6761b84f`
- Size: 43409791 bytes
- Version: 3.218
- Release date: 2024-07-27 16:31:59

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/252f9e3923778861 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/252f9e3923778861/_openwrt-mv1000-emmc-3.218-0727-1722069119.img.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
