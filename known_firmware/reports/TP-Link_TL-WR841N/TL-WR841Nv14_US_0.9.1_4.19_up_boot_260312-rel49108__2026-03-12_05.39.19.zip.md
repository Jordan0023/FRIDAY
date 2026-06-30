# Firmware Audit: TP-Link TL-WR841N / TL-WR841Nv14_US_0.9.1_4.19_up_boot_260312-rel49108__2026-03-12_05.39.19.zip

- Source URL: https://static.tp-link.com/upload/firmware/2026/202603/20260313/TL-WR841Nv14_US_0.9.1_4.19_up_boot[260312-rel49108]_2026-03-12_05.39.19.zip
- Local path: known_firmware/firmware/TP-Link_TL-WR841N/TL-WR841Nv14_US_0.9.1_4.19_up_boot_260312-rel49108__2026-03-12_05.39.19.zip
- SHA-256: `53525db22c82dd9e49862d96fea462cceaffa8e587a536ff3a6d4fa76e8774a5`
- Size: 4015661 bytes
- Version: unknown
- Release date: 2026-03-13

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/53525db22c82dd9e exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/53525db22c82dd9e/_TL-WR841Nv14_US_0.9.1_4.19_up_boot_260312-rel49108__2026-03-12_05.39.19.zip.extracted/_TL-WR841Nv14_US_0.9.1_4.19_up_boot[260312-rel49108]_2026-03-12_05.39.19.bin.extracted/squashfs-root-0/etc/passwd -> /var/passwd; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
