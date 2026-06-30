# Firmware Audit: GL.iNet GL-B3000 Marble / openwrt-b3000-4.5.22-0407-1744021171.img

- Source URL: https://fw.gl-inet.com/firmware/b3000/release/openwrt-b3000-4.5.22-0407-1744021171.img
- Local path: known_firmware/firmware/GL.iNet_GL-B3000_Marble/openwrt-b3000-4.5.22-0407-1744021171.img
- SHA-256: `4beef3c6ca44d3fd057003144781309cf7d863d439c298dc9f4354629594e43f`
- Size: 59812441 bytes
- Version: 4.5.22
- Release date: 2025-04-07 17:38:39

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4beef3c6ca44d3fd exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
