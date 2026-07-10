# Firmware Audit: OpenWrt Sony NCP-HG100/Cellular / openwrt-25.12.5-ipq40xx-generic-sony_ncp-hg100-cellular-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq40xx/generic/openwrt-25.12.5-ipq40xx-generic-sony_ncp-hg100-cellular-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Sony_NCP-HG100_Cellular/openwrt-25.12.5-ipq40xx-generic-sony_ncp-hg100-cellular-squashfs-sysupgrade.bin
- SHA-256: `17890a11f247d5628cdbd9b7e552fa32f9705b6f095962815a7788aa0a2fbc05`
- Size: 10220096 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/17890a11f247d562 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/17890a11f247d562/_openwrt-25.12.5-ipq40xx-generic-sony_ncp-hg100-cellular-squashfs-sysupgrade.bin.extracted/sysupgrade-sony_ncp-hg100-cellular/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
