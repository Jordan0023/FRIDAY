# Firmware Audit: GL.iNet GL-MT3000 Beryl AX / openwrt-mt3000-4.1.2-1205-1670228220.bin

- Source URL: https://fw.gl-inet.com/firmware/mt3000/release/openwrt-mt3000-4.1.2-1205-1670228220.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT3000_Beryl_AX/openwrt-mt3000-4.1.2-1205-1670228220.bin
- SHA-256: `48731a8e819d68cba9042fe2b4418a2f39c4f2c4b78ec3955741d8d867ad697e`
- Size: 53443548 bytes
- Version: 4.1.2
- Release date: 2022-12-05 16:17:50

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, bOA, bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/48731a8e819d68cb exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/48731a8e819d68cb/_openwrt-mt3000-4.1.2-1205-1670228220.bin.extracted/sysupgrade-glinet_gl-mt3000/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
