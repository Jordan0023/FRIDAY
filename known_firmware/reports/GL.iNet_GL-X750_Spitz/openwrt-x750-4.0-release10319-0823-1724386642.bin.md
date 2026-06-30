# Firmware Audit: GL.iNet GL-X750 Spitz / openwrt-x750-4.0-release10319-0823-1724386642.bin

- Source URL: https://fw.gl-inet.com/firmware/x750/release4/openwrt-x750-4.0-release10319-0823-1724386642.bin
- Local path: known_firmware/firmware/GL.iNet_GL-X750_Spitz/openwrt-x750-4.0-release10319-0823-1724386642.bin
- SHA-256: `3548e4e593347c20a493ef16a0e18a63f4ba656417e953edfc4c790903acbbc1`
- Size: 15008483 bytes
- Version: 4.3.19
- Release date: 2024-08-23 12:15:42

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3548e4e593347c20 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/3548e4e593347c20/_openwrt-x750-4.0-release10319-0823-1724386642.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
