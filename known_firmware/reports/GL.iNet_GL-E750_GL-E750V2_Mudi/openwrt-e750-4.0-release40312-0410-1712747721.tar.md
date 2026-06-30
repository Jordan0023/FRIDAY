# Firmware Audit: GL.iNet GL-E750/GL-E750V2 Mudi / openwrt-e750-4.0-release40312-0410-1712747721.tar

- Source URL: https://fw.gl-inet.com/firmware/e750/release4/openwrt-e750-4.0-release40312-0410-1712747721.tar
- Local path: known_firmware/firmware/GL.iNet_GL-E750_GL-E750V2_Mudi/openwrt-e750-4.0-release40312-0410-1712747721.tar
- SHA-256: `34a06fdafc0d61331f38995fe934de9c040a587701af061f50a57b22d470431a`
- Size: 18361288 bytes
- Version: 4.3.12
- Release date: 2024-04-10 19:13:44

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/34a06fdafc0d6133 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/34a06fdafc0d6133/_openwrt-e750-4.0-release40312-0410-1712747721.tar.extracted/sysupgrade-glinet_gl-e750/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
