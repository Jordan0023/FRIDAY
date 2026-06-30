# Firmware Audit: TP-Link Archer C20 / Archer_C20_CPI__V6.6_260519.zip

- Source URL: https://static.tp-link.com/upload/firmware/2026/202605/20260521/Archer C20(CPI)_V6.6_260519.zip
- Local path: known_firmware/firmware/TP-Link_Archer_C20/Archer_C20_CPI__V6.6_260519.zip
- SHA-256: `9928e3f80c24fecdd8abac83cb0ff4fb0ed08b09701e7d52638201b0618284e3`
- Size: 7704741 bytes
- Version: unknown
- Release date: 2026-05-21

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9928e3f80c24fecd exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/9928e3f80c24fecd/_Archer_C20_CPI__V6.6_260519.zip.extracted/_Archer_C20v6_0.9.1_4.20_up_boot[260519-rel54153]_2026-05-19_00.03.32.bin.extracted/squashfs-root/etc/passwd -> /var/passwd; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
