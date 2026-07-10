# Firmware Audit: OpenWrt Fortinet FAP-221-C / openwrt-25.12.5-ath79-generic-fortinet_fap-221-c-squashfs-sysupgrade.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-fortinet_fap-221-c-squashfs-sysupgrade.bin
- Local path: known_firmware/firmware/OpenWrt_Fortinet_FAP-221-C/openwrt-25.12.5-ath79-generic-fortinet_fap-221-c-squashfs-sysupgrade.bin
- SHA-256: `6d950108a341535001a5c10be2ff44aa907c77956c2b610eb47c5e96b6c34bf1`
- Size: 7265866 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Private keys or certificates bundled in firmware

Embedded private keys/certificates can allow credential reuse or impersonation if shared across devices.

Evidence: `-----BEGIN CERTIFICATE-----`

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `password`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, boa`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6d950108a3415350 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/6d950108a3415350/_openwrt-25.12.5-ath79-generic-fortinet_fap-221-c-squashfs-sysupgrade.bin.extracted/_0.extracted/_openwrt-ar71xx-generic-ens1750-root.squashfs.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
