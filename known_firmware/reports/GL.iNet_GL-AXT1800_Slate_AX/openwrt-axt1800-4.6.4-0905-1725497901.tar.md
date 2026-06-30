# Firmware Audit: GL.iNet GL-AXT1800 Slate AX / openwrt-axt1800-4.6.4-0905-1725497901.tar

- Source URL: https://fw.gl-inet.com/firmware/axt1800/release/openwrt-axt1800-4.6.4-0905-1725497901.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AXT1800_Slate_AX/openwrt-axt1800-4.6.4-0905-1725497901.tar
- SHA-256: `f5912ed8f1add984cc1a6226f43fd52402821216ee36536313ae61f798a6e810`
- Size: 47077372 bytes
- Version: 4.6.4
- Release date: 2024-09-05 08:22:50

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, Boa, bOA, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f5912ed8f1add984 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/f5912ed8f1add984/_openwrt-axt1800-4.6.4-0905-1725497901.tar.extracted/sysupgrade-glinet_axt1800/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
