# Firmware Audit: GL.iNet GL-AR150 White / openwrt-ar150-3.215-0921-1663732120.bin

- Source URL: https://fw.gl-inet.com/firmware/ar150/v1/openwrt-ar150-3.215-0921-1663732120.bin
- Local path: known_firmware/firmware/GL.iNet_GL-AR150_White/openwrt-ar150-3.215-0921-1663732120.bin
- SHA-256: `cafe39150c87d9198f936bc67794be805bc6855bda8547a9f722273d466696b1`
- Size: 12583228 bytes
- Version: 3.215
- Release date: 2022-09-21 11:48:40

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, bOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/cafe39150c87d919 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/cafe39150c87d919/_openwrt-ar150-3.215-0921-1663732120.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
