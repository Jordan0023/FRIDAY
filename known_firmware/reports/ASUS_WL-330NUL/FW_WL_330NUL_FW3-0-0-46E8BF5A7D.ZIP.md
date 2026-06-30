# Firmware Audit: ASUS WL-330NUL / FW_WL_330NUL_FW3-0-0-46E8BF5A7D.ZIP

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/WL-330NUL/FW_WL_330NUL_FW3-0-0-46E8BF5A7D.ZIP
- Local path: known_firmware/firmware/ASUS_WL-330NUL/FW_WL_330NUL_FW3-0-0-46E8BF5A7D.ZIP
- SHA-256: `cb4b000246c925747f1261fdbd4324359596ed6f2954f58f30089e778eb116b1`
- Size: 10230965 bytes
- Version: 3.0.0.46
- Release date: 2016/06/20

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/cb4b000246c92574 exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/cb4b000246c92574/_FW_WL_330NUL_FW3-0-0-46E8BF5A7D.ZIP.extracted/_WL-330NUL_FW_3-0-0-46_e8bf5a7d.trx.extracted/squashfs-root/bin/iptables-restore -> /usr/bin/iptables; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
