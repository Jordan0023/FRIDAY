# Firmware Audit: GL.iNet GL-MT1300 Beryl / openwrt-mt1300-4.3.11-0320-1710944013.bin

- Source URL: https://fw.gl-inet.com/firmware/mt1300/release4/openwrt-mt1300-4.3.11-0320-1710944013.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT1300_Beryl/openwrt-mt1300-4.3.11-0320-1710944013.bin
- SHA-256: `01413237e627c65394431f5d22b7ddfa644768b4de15fe73604701fe9b4ccc05`
- Size: 16779350 bytes
- Version: 4.3.11
- Release date: 2024-03-20 22:11:51

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/01413237e627c653 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/01413237e627c653/_openwrt-mt1300-4.3.11-0320-1710944013.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
