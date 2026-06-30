# Firmware Audit: GL.iNet GL-MT300N-V2 Mango / openwrt-mt300n-v2-3.216-0321-1679391429.bin

- Source URL: https://fw.gl-inet.com/firmware/mt300n-v2/v1/openwrt-mt300n-v2-3.216-0321-1679391429.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT300N-V2_Mango/openwrt-mt300n-v2-3.216-0321-1679391429.bin
- SHA-256: `22b0eb598ad18116de509b8ab4c706a236c573a4ff603cca7528da5b92336346`
- Size: 12583196 bytes
- Version: 3.216
- Release date: 2023-03-21 17:37:09

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/22b0eb598ad18116 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/22b0eb598ad18116/_openwrt-mt300n-v2-3.216-0321-1679391429.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
