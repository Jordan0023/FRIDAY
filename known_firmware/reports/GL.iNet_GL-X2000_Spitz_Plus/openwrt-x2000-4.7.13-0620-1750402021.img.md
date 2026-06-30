# Firmware Audit: GL.iNet GL-X2000 Spitz Plus / openwrt-x2000-4.7.13-0620-1750402021.img

- Source URL: https://fw.gl-inet.com/firmware/x2000/release/openwrt-x2000-4.7.13-0620-1750402021.img
- Local path: known_firmware/firmware/GL.iNet_GL-X2000_Spitz_Plus/openwrt-x2000-4.7.13-0620-1750402021.img
- SHA-256: `83844f777d2cdf6189ad4ccf2719266e45d8d8726348d9b1bd3e01725ead05b5`
- Size: 72266960 bytes
- Version: 4.7.13
- Release date: 2025-06-20 14:18:42

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/83844f777d2cdf61 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
