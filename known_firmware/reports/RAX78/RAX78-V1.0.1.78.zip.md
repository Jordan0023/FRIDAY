# Firmware Audit: RAX78 / RAX78-V1.0.1.78.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX78/RAX78-V1.0.1.78.zip
- Local path: known_firmware/firmware/RAX78/RAX78-V1.0.1.78.zip
- SHA-256: `b23e8adfefaa2831934fed5b1121cbd383ca3577678bfbe240edd559e4e8b434`
- Size: 72715360 bytes
- Version: 1.0.1.78
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b23e8adfefaa2831 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
