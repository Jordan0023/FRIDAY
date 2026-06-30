# Firmware Audit: GL.iNet GL-AR300M16 Shadow / openwrt-ar300m16-4.3.11-0320-1710939596.bin

- Source URL: https://fw.gl-inet.com/firmware/ar300m/release4/openwrt-ar300m16-4.3.11-0320-1710939596.bin
- Local path: known_firmware/firmware/GL.iNet_GL-AR300M16_Shadow/openwrt-ar300m16-4.3.11-0320-1710939596.bin
- SHA-256: `a3f5fa4642df519b60d60440c49a8233521735ee7d6f6485f7706b9818b4c4bb`
- Size: 15402839 bytes
- Version: 4.3.11
- Release date: 2024-03-20 20:58:16

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a3f5fa4642df519b exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/a3f5fa4642df519b/_openwrt-ar300m16-4.3.11-0320-1710939596.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
