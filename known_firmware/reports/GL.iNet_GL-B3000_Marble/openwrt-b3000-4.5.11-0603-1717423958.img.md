# Firmware Audit: GL.iNet GL-B3000 Marble / openwrt-b3000-4.5.11-0603-1717423958.img

- Source URL: https://fw.gl-inet.com/firmware/b3000/release/openwrt-b3000-4.5.11-0603-1717423958.img
- Local path: known_firmware/firmware/GL.iNet_GL-B3000_Marble/openwrt-b3000-4.5.11-0603-1717423958.img
- SHA-256: `94e111d0667e6718d36e7e82473e6d9f8dd88e1710315ebc4b7837651ec7a2a7`
- Size: 62827176 bytes
- Version: 4.5.11
- Release date: 2024-06-03 21:37:34

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/94e111d0667e6718 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
