# Firmware Audit: GL.iNet GL-B3000 Marble / openwrt-b3000-4.5.15-0717-1721216281.img

- Source URL: https://fw.gl-inet.com/firmware/b3000/release/openwrt-b3000-4.5.15-0717-1721216281.img
- Local path: known_firmware/firmware/GL.iNet_GL-B3000_Marble/openwrt-b3000-4.5.15-0717-1721216281.img
- SHA-256: `9ea1477db40a0e649b16fc522534d4337ec03b9357f6f552b9b9a7c86bbc9540`
- Size: 60075603 bytes
- Version: 4.5.15
- Release date: 2024-07-17 19:03:22

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9ea1477db40a0e64 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
