# Firmware Audit: JNR3210 / JNR3210_Firmware_Version_1.1.0.14.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/JNR3210/JNR3210%20Firmware%20Version%201.1.0.14.zip
- Local path: known_firmware/firmware/JNR3210/JNR3210_Firmware_Version_1.1.0.14.zip
- SHA-256: `59b8375ac64139e506a5a8bd4a9f94b859330a4701be3ea28edd1797d89f15c7`
- Size: 6745905 bytes
- Version: 1.0.14
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/59b8375ac64139e5 exited 0: WARNING: Extractor.execute failed to run external extractor 'jar xvf '%e'': [Errno 2] No such file or directory: 'jar', 'jar xvf '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
