# Firmware Audit: GL.iNet GL-A1300 Slate Plus / openwrt-a1300-4.4.5-0811-1691737355.tar

- Source URL: https://fw.gl-inet.com/firmware/a1300/release/openwrt-a1300-4.4.5-0811-1691737355.tar
- Local path: known_firmware/firmware/GL.iNet_GL-A1300_Slate_Plus/openwrt-a1300-4.4.5-0811-1691737355.tar
- SHA-256: `79c4e63c40c2053adc1bec77c9bb7b3d77c2cfc5d36443d1dcd23ed0d204bae8`
- Size: 56331611 bytes
- Version: 4.4.5
- Release date: 2023-08-11 15:00:32

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, bOA, bOa, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/79c4e63c40c2053a exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/79c4e63c40c2053a/_openwrt-a1300-4.4.5-0811-1691737355.tar.extracted/sysupgrade-glinet_gl-a1300/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
