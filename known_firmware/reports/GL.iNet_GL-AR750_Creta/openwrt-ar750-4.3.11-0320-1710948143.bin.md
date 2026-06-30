# Firmware Audit: GL.iNet GL-AR750 Creta / openwrt-ar750-4.3.11-0320-1710948143.bin

- Source URL: https://fw.gl-inet.com/firmware/ar750/release4/openwrt-ar750-4.3.11-0320-1710948143.bin
- Local path: known_firmware/firmware/GL.iNet_GL-AR750_Creta/openwrt-ar750-4.3.11-0320-1710948143.bin
- SHA-256: `0c60bc5d41891c5a267d9dad74c29629bf70cb185b9708078b942c79b5c34149`
- Size: 14812998 bytes
- Version: 4.3.11
- Release date: 2024-03-20 23:20:48

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0c60bc5d41891c5a exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/0c60bc5d41891c5a/_openwrt-ar750-4.3.11-0320-1710948143.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
