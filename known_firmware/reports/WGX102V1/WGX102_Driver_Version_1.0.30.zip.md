# Firmware Audit: WGX102V1 / WGX102_Driver_Version_1.0.30.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGX102v1/WGX102%20Driver%20Version%201.0.30.zip
- Local path: known_firmware/firmware/WGX102V1/WGX102_Driver_Version_1.0.30.zip
- SHA-256: `20061de3ffeaaad4b92b820fde1313f759b3fba492a6e747c7560ea9b4130f9a`
- Size: 1713851 bytes
- Version: 0.30
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/20061de3ffeaaad4 exited 0: WARNING: Extractor.execute failed to run external extractor 'jar xvf '%e'': [Errno 2] No such file or directory: 'jar', 'jar xvf '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
