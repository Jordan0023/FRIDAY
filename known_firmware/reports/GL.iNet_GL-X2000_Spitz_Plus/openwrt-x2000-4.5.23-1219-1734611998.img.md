# Firmware Audit: GL.iNet GL-X2000 Spitz Plus / openwrt-x2000-4.5.23-1219-1734611998.img

- Source URL: https://fw.gl-inet.com/firmware/x2000/release/openwrt-x2000-4.5.23-1219-1734611998.img
- Local path: known_firmware/firmware/GL.iNet_GL-X2000_Spitz_Plus/openwrt-x2000-4.5.23-1219-1734611998.img
- SHA-256: `224b39b1b5a0e5f13328f7bf8cd9bf2573c21d2639962e68ab47695618b638de`
- Size: 60336700 bytes
- Version: 4.5.23
- Release date: 2024-12-19 19:57:21

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/224b39b1b5a0e5f1 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
