# Firmware Audit: GL.iNet GL-MT300N-V2 Mango / openwrt-mt300n-v2-4.3.11-0326-1711435079.bin

- Source URL: https://fw.gl-inet.com/firmware/mt300n-v2/release4/openwrt-mt300n-v2-4.3.11-0326-1711435079.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT300N-V2_Mango/openwrt-mt300n-v2-4.3.11-0326-1711435079.bin
- SHA-256: `45465178db30815602c5284f29b10f55d47b7d92cc0af3d97fe32991817dcc07`
- Size: 14681908 bytes
- Version: 4.3.11
- Release date: 2024-03-26 14:36:26

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/45465178db308156 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/45465178db308156/_openwrt-mt300n-v2-4.3.11-0326-1711435079.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
