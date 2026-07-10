# Firmware Audit: OpenWrt Etisalat S3 / openwrt-25.12.5-ramips-mt7621-etisalat_s3-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-etisalat_s3-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Etisalat_S3/openwrt-25.12.5-ramips-mt7621-etisalat_s3-squashfs-sysupgrade.bin
- SHA-256: `3e0f5af644f35f732291bd42d75988f6eb182ff11dadd1750ebda357c4c2c5e9`
- Size: 8366618 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3e0f5af644f35f73 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/3e0f5af644f35f73/_openwrt-25.12.5-ramips-mt7621-etisalat_s3-squashfs-sysupgrade.bin.extracted/sysupgrade-etisalat_s3/_root.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
