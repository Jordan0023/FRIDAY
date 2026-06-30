# Firmware Audit: GL.iNet GL-X2000 Spitz Plus / openwrt-x2000-4.5.26-0307-1741096556.img

- Source URL: https://fw.gl-inet.com/firmware/x2000/release/openwrt-x2000-4.5.26-0307-1741096556.img
- Local path: known_firmware/firmware/GL.iNet_GL-X2000_Spitz_Plus/openwrt-x2000-4.5.26-0307-1741096556.img
- SHA-256: `80e63f2eb3c8a771cdf33a3e57a62f50fafe8154cad4c8e23be7241d47fb4223`
- Size: 60336859 bytes
- Version: 4.5.26
- Release date: 2025-03-04 21:31:45

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/80e63f2eb3c8a771 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
