# Firmware Audit: GL.iNet GL-MT1300 Beryl / openwrt-mt1300-4.3.25-0331-1743430041.bin

- Source URL: https://fw.gl-inet.com/firmware/mt1300/release4/openwrt-mt1300-4.3.25-0331-1743430041.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT1300_Beryl/openwrt-mt1300-4.3.25-0331-1743430041.bin
- SHA-256: `e906a213ed66027b8e801b9c621f7ce8c43f70098615c0278a8250cc3beeb82c`
- Size: 17040545 bytes
- Version: 4.3.25
- Release date: 2025-03-31 22:06:45

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e906a213ed66027b exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e906a213ed66027b/_openwrt-mt1300-4.3.25-0331-1743430041.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
