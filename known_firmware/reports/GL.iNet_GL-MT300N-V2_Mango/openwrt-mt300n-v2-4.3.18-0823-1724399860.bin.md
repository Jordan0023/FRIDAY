# Firmware Audit: GL.iNet GL-MT300N-V2 Mango / openwrt-mt300n-v2-4.3.18-0823-1724399860.bin

- Source URL: https://fw.gl-inet.com/firmware/mt300n-v2/release4/openwrt-mt300n-v2-4.3.18-0823-1724399860.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT300N-V2_Mango/openwrt-mt300n-v2-4.3.18-0823-1724399860.bin
- SHA-256: `d2b6c2499c7f7262818de129828de16d2e86bf40cadf45bdf496fab69c79b2d0`
- Size: 14680902 bytes
- Version: 4.3.18
- Release date: 2024-08-23 15:56:00

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d2b6c2499c7f7262 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/d2b6c2499c7f7262/_openwrt-mt300n-v2-4.3.18-0823-1724399860.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
