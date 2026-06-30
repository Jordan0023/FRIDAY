# Firmware Audit: TP-Link TL-WR802N / TL-WR802Nv4_US_0.9.1_3.17_up_boot_260312-rel49566__2026-03-12_05.46.23.zip

- Source URL: https://static.tp-link.com/upload/firmware/2026/202603/20260313/TL-WR802Nv4_US_0.9.1_3.17_up_boot[260312-rel49566]_2026-03-12_05.46.23.zip
- Local path: known_firmware/firmware/TP-Link_TL-WR802N/TL-WR802Nv4_US_0.9.1_3.17_up_boot_260312-rel49566__2026-03-12_05.46.23.zip
- SHA-256: `5d274a458d1b6bc7d6632c19c4aa033ccd2ef9f5b6f7e3a238230cc85bd4019c`
- Size: 5908819 bytes
- Version: unknown
- Release date: 2026-03-13

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `password`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `inetd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5d274a458d1b6bc7 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/5d274a458d1b6bc7/_TL-WR802Nv4_US_0.9.1_3.17_up_boot_260312-rel49566__2026-03-12_05.46.23.zip.extracted/_TL-WR802Nv4_US_0.9.1_3.17_up_boot[260312-rel49566]_2026-03-12_05.46.23.bin.extracted/squashfs-root/etc/passwd -> /var/passwd; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
