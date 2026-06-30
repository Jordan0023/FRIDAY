# Firmware Audit: GL.iNet GL-X750 Spitz / openwrt-x750-3.216-0321-1679391067.bin

- Source URL: https://fw.gl-inet.com/firmware/x750/release/openwrt-x750-3.216-0321-1679391067.bin
- Local path: known_firmware/firmware/GL.iNet_GL-X750_Spitz/openwrt-x750-3.216-0321-1679391067.bin
- SHA-256: `3a42762cee6135aeb389138ddcff9e3120ab9e38ecfaee5f24b73706f053b76c`
- Size: 13107520 bytes
- Version: 3.216
- Release date: 2023-03-21 17:31:07

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3a42762cee6135ae exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/3a42762cee6135ae/_openwrt-x750-3.216-0321-1679391067.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
