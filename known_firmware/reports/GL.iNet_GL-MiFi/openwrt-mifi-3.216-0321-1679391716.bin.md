# Firmware Audit: GL.iNet GL-MiFi / openwrt-mifi-3.216-0321-1679391716.bin

- Source URL: https://fw.gl-inet.com/firmware/mifi/v1/openwrt-mifi-3.216-0321-1679391716.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MiFi/openwrt-mifi-3.216-0321-1679391716.bin
- SHA-256: `7e203fd78071b428b88744be0adda371afd9d862dae7882606b5ee3c0fdfa9bc`
- Size: 12714296 bytes
- Version: 3.216
- Release date: 2023-03-21 17:41:56

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/7e203fd78071b428 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/7e203fd78071b428/_openwrt-mifi-3.216-0321-1679391716.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
