# Firmware Audit: GL.iNet GL-MT1300 Beryl / openwrt-mt1300-4.3.17-0607-1717703270.bin

- Source URL: https://fw.gl-inet.com/firmware/mt1300/release4/openwrt-mt1300-4.3.17-0607-1717703270.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT1300_Beryl/openwrt-mt1300-4.3.17-0607-1717703270.bin
- SHA-256: `29a31700a5b20d30176edc6879c064c190358b273ced42b599888fda3b1851f4`
- Size: 17041096 bytes
- Version: 4.3.17
- Release date: 2024-06-07 03:45:57

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/29a31700a5b20d30 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/29a31700a5b20d30/_openwrt-mt1300-4.3.17-0607-1717703270.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
