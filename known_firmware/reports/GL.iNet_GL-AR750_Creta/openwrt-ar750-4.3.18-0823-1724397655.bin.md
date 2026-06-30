# Firmware Audit: GL.iNet GL-AR750 Creta / openwrt-ar750-4.3.18-0823-1724397655.bin

- Source URL: https://fw.gl-inet.com/firmware/ar750/release4/openwrt-ar750-4.3.18-0823-1724397655.bin
- Local path: known_firmware/firmware/GL.iNet_GL-AR750_Creta/openwrt-ar750-4.3.18-0823-1724397655.bin
- SHA-256: `dfbfeadf0217ae086f0c15d8084923599105ed4422ae2dfd3bcf4a7ad072317c`
- Size: 14877528 bytes
- Version: 4.3.18
- Release date: 2024-08-23 15:19:13

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/dfbfeadf0217ae08 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/dfbfeadf0217ae08/_openwrt-ar750-4.3.18-0823-1724397655.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
