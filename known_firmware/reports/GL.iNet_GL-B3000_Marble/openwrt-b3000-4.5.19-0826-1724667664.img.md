# Firmware Audit: GL.iNet GL-B3000 Marble / openwrt-b3000-4.5.19-0826-1724667664.img

- Source URL: https://fw.gl-inet.com/firmware/b3000/release/openwrt-b3000-4.5.19-0826-1724667664.img
- Local path: known_firmware/firmware/GL.iNet_GL-B3000_Marble/openwrt-b3000-4.5.19-0826-1724667664.img
- SHA-256: `f865155b7e3094053efc8a6c5c2f5e4a7f2e40c17a270e537ffe4d7c2dcb010b`
- Size: 60074658 bytes
- Version: 4.5.19
- Release date: 2024-08-26 17:39:21

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f865155b7e309405 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
