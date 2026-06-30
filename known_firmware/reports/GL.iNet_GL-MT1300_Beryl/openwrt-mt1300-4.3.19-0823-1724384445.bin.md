# Firmware Audit: GL.iNet GL-MT1300 Beryl / openwrt-mt1300-4.3.19-0823-1724384445.bin

- Source URL: https://fw.gl-inet.com/firmware/mt1300/release4/openwrt-mt1300-4.3.19-0823-1724384445.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT1300_Beryl/openwrt-mt1300-4.3.19-0823-1724384445.bin
- SHA-256: `258f29fb043f772c362e412e49ee59878c494b961e1100dfedb22e2a01a77251`
- Size: 17040367 bytes
- Version: 4.3.19
- Release date: 2024-08-23 11:38:53

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/258f29fb043f772c exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/258f29fb043f772c/_openwrt-mt1300-4.3.19-0823-1724384445.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
