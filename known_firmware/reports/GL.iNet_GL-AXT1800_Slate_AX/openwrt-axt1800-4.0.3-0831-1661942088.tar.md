# Firmware Audit: GL.iNet GL-AXT1800 Slate AX / openwrt-axt1800-4.0.3-0831-1661942088.tar

- Source URL: https://fw.gl-inet.com/firmware/axt1800/release/openwrt-axt1800-4.0.3-0831-1661942088.tar
- Local path: known_firmware/firmware/GL.iNet_GL-AXT1800_Slate_AX/openwrt-axt1800-4.0.3-0831-1661942088.tar
- SHA-256: `95371806941e6b6eecfc447db41414e741b70c217027ca129f752853ab9d4b32`
- Size: 49592938 bytes
- Version: 4.0.3
- Release date: 2022-08-31 18:34:48

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `ssHD`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, Boa, bOA, bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/95371806941e6b6e exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/95371806941e6b6e/_openwrt-axt1800-4.0.3-0831-1661942088.tar.extracted/sysupgrade-glinet_axt1800/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
