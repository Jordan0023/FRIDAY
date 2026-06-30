# Firmware Audit: JNR3000 / JNR3000_Firmware_Version_1.1.0.14.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/JNR3000/JNR3000%20Firmware%20Version%201.1.0.14.zip
- Local path: known_firmware/firmware/JNR3000/JNR3000_Firmware_Version_1.1.0.14.zip
- SHA-256: `2adf6eb887484b9320e5fb8ce7fd461042e85c7a864b432efb51df9c13b30233`
- Size: 6745883 bytes
- Version: 1.0.14
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/2adf6eb887484b93 exited 0: WARNING: Extractor.execute failed to run external extractor 'jar xvf '%e'': [Errno 2] No such file or directory: 'jar', 'jar xvf '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
