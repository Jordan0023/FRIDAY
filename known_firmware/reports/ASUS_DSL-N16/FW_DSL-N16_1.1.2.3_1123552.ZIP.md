# Firmware Audit: ASUS DSL-N16 / FW_DSL-N16_1.1.2.3_1123552.ZIP

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N16/FW_DSL-N16_1.1.2.3_1123552.ZIP
- Local path: known_firmware/firmware/ASUS_DSL-N16/FW_DSL-N16_1.1.2.3_1123552.ZIP
- SHA-256: `2aaf0119c1aab3b65f46a77b7a8155c9467eeff182a23e683c8f18174c00fc57`
- Size: 9238047 bytes
- Version: 1.1.2.3_552
- Release date: 2018/09/05

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2aaf0119c1aab3b6 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/2aaf0119c1aab3b6/_FW_DSL-N16_1.1.2.3_1123552.ZIP.extracted/_DSL-N16_1.1.2.3_552-g3626ab6.trx.extracted/squashfs-root/usr/sbin/pppd -> /usr/bin/pppd; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
