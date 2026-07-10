# Firmware Audit: OpenWrt Qualcomm DB149 / openwrt-25.12.5-ipq806x-generic-qcom_ipq8064-db149-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq806x/generic/openwrt-25.12.5-ipq806x-generic-qcom_ipq8064-db149-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Qualcomm_DB149/openwrt-25.12.5-ipq806x-generic-qcom_ipq8064-db149-squashfs-sysupgrade.bin
- SHA-256: `bdf5ba79ae154b93a831d9f4d209af07c0ef559cc8b40799d108cd151a95db0b`
- Size: 9718308 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/bdf5ba79ae154b93 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/bdf5ba79ae154b93/_openwrt-25.12.5-ipq806x-generic-qcom_ipq8064-db149-squashfs-sysupgrade.bin.extracted/sysupgrade-db149/_root.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
