# Firmware Audit: GL.iNet GL-AR300M16 Shadow / openwrt-ar300m16-4.3.17-0607-1717697077.bin

- Source URL: https://fw.gl-inet.com/firmware/ar300m/release4/openwrt-ar300m16-4.3.17-0607-1717697077.bin
- Local path: known_firmware/firmware/GL.iNet_GL-AR300M16_Shadow/openwrt-ar300m16-4.3.17-0607-1717697077.bin
- SHA-256: `95ec97e950f51389e80f9f84d659962e7664b63fd1ac55ef8c078c52d259849e`
- Size: 15467977 bytes
- Version: 4.3.17
- Release date: 2024-06-07 02:03:00

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/95ec97e950f51389 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/95ec97e950f51389/_openwrt-ar300m16-4.3.17-0607-1717697077.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
