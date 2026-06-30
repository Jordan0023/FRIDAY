# Firmware Audit: WGU624 / WGU624_Firmware_Version_2.0.1.1.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGU624/WGU624%20Firmware%20Version%202.0.1.1.zip
- Local path: known_firmware/firmware/WGU624/WGU624_Firmware_Version_2.0.1.1.zip
- SHA-256: `495f11c5c79bf0b7daf52e3493d35654dbce0fb6c12ff38eb27557a56e041380`
- Size: 952423 bytes
- Version: 0.1.1
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `SYSTEM, System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/495f11c5c79bf0b7 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
