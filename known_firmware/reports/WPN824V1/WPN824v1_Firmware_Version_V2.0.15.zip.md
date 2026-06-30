# Firmware Audit: WPN824V1 / WPN824v1_Firmware_Version_V2.0.15.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WPN824V1/WPN824v1%20Firmware%20Version%20V2.0.15.zip
- Local path: known_firmware/firmware/WPN824V1/WPN824v1_Firmware_Version_V2.0.15.zip
- SHA-256: `aead39dedbda7e1c9f93216ae0bc4b2a1ce57eab3271ea317e71dd8c5f3fad6c`
- Size: 1223585 bytes
- Version: 0.15
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/aead39dedbda7e1c exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
