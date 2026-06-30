# Firmware Audit: RT311 / Firmware_version_3.24_for_the_RT311_and_RT314.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RT311/Firmware%20version%203.24%20for%20the%20RT311%20and%20RT314.zip
- Local path: known_firmware/firmware/RT311/Firmware_version_3.24_for_the_RT311_and_RT314.zip
- SHA-256: `36269e9b6e304bdd37a61b6cad03704646edb345406e7e253eb9082c22df16cd`
- Size: 1303677 bytes
- Version: unknown
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/36269e9b6e304bdd exited 0: WARNING: Extractor.execute failed to run external extractor 'jar xvf '%e'': [Errno 2] No such file or directory: 'jar', 'jar xvf '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
