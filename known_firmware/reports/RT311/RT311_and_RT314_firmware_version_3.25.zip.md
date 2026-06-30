# Firmware Audit: RT311 / RT311_and_RT314_firmware_version_3.25.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RT311/RT311%20and%20RT314%20firmware%20version%203.25.zip
- Local path: known_firmware/firmware/RT311/RT311_and_RT314_firmware_version_3.25.zip
- SHA-256: `9fae576917f7440183bcf4f4fa1a0bbd7180b2366165ee72f717dc30ac09faa3`
- Size: 852234 bytes
- Version: unknown
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9fae576917f74401 exited 0: WARNING: Extractor.execute failed to run external extractor 'jar xvf '%e'': [Errno 2] No such file or directory: 'jar', 'jar xvf '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
