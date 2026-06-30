# Firmware Audit: GL.iNet GL-MT300N-V2 Mango / openwrt-mt300n-v2-3.215-1013-1665642015.bin

- Source URL: https://fw.gl-inet.com/firmware/mt300n-v2/v1/openwrt-mt300n-v2-3.215-1013-1665642015.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT300N-V2_Mango/openwrt-mt300n-v2-3.215-1013-1665642015.bin
- SHA-256: `8d761ac6a66598a5b197089e6502865f4fe248015532994d632f7b5757399fc7`
- Size: 12583196 bytes
- Version: 3.215
- Release date: 2022-10-13 14:20:15

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/8d761ac6a66598a5 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/8d761ac6a66598a5/_openwrt-mt300n-v2-3.215-1013-1665642015.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
