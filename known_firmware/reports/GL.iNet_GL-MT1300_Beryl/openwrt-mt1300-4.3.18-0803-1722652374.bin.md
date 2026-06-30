# Firmware Audit: GL.iNet GL-MT1300 Beryl / openwrt-mt1300-4.3.18-0803-1722652374.bin

- Source URL: https://fw.gl-inet.com/firmware/mt1300/release4/openwrt-mt1300-4.3.18-0803-1722652374.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT1300_Beryl/openwrt-mt1300-4.3.18-0803-1722652374.bin
- SHA-256: `1a5b02ba907d33e8a3489dc69ed2b0cdd3ee0e2971b7d35fc7ddd887bf950486`
- Size: 17041652 bytes
- Version: 4.3.18
- Release date: 2024-08-03 10:31:03

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1a5b02ba907d33e8 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/1a5b02ba907d33e8/_openwrt-mt1300-4.3.18-0803-1722652374.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
