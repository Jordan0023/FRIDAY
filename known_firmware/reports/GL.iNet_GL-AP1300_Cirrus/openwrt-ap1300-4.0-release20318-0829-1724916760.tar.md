# Firmware Audit: GL.iNet GL-AP1300 Cirrus / openwrt-ap1300-4.0-release20318-0829-1724916760.tar

- Source URL: https://fw.gl-inet.com/firmware/ap1300/release4/openwrt-ap1300-4.0-release20318-0829-1724916760.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AP1300_Cirrus/openwrt-ap1300-4.0-release20318-0829-1724916760.tar
- SHA-256: `f4fd3a7a07dc3df2bb1f26360177d5b96ae31b862b73086bcf99e43e6179be33`
- Size: 26880842 bytes
- Version: 4.3.18
- Release date: 2024-08-29 15:30:03

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f4fd3a7a07dc3df2 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/f4fd3a7a07dc3df2/_openwrt-ap1300-4.0-release20318-0829-1724916760.tar.extracted/sysupgrade-glinet_gl-ap1300/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
