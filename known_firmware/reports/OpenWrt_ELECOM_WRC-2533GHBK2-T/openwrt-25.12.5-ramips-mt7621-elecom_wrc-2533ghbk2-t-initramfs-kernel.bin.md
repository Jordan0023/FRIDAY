# Firmware Audit: OpenWrt ELECOM WRC-2533GHBK2-T / openwrt-25.12.5-ramips-mt7621-elecom_wrc-2533ghbk2-t-initramfs-kernel.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ramips/mt7621/openwrt-25.12.5-ramips-mt7621-elecom_wrc-2533ghbk2-t-initramfs-kernel.bin
- Local path: known_firmware/firmware/OpenWrt_ELECOM_WRC-2533GHBK2-T/openwrt-25.12.5-ramips-mt7621-elecom_wrc-2533ghbk2-t-initramfs-kernel.bin
- SHA-256: `fb248f09bdbc7b3d76fdf5c01d560d13508d646f39948feec6950d84bb480e82`
- Size: 7908748 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA, bOA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/fb248f09bdbc7b3d exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/fb248f09bdbc7b3d/_openwrt-25.12.5-ramips-mt7621-elecom_wrc-2533ghbk2-t-initramfs-kernel.bin.extracted/_168C.extracted/_A77ED4.extracted/cpio-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
