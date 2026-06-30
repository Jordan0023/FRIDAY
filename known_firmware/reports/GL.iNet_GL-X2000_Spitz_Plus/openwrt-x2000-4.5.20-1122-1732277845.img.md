# Firmware Audit: GL.iNet GL-X2000 Spitz Plus / openwrt-x2000-4.5.20-1122-1732277845.img

- Source URL: https://fw.gl-inet.com/firmware/x2000/release/openwrt-x2000-4.5.20-1122-1732277845.img
- Local path: known_firmware/firmware/GL.iNet_GL-X2000_Spitz_Plus/openwrt-x2000-4.5.20-1122-1732277845.img
- SHA-256: `582549fbe0b5252deaad6a179121bc7c4d62b603b68ed9ce86e1b97848570063`
- Size: 60337331 bytes
- Version: 4.5.20
- Release date: 2024-11-22 19:32:53

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/582549fbe0b5252d exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
