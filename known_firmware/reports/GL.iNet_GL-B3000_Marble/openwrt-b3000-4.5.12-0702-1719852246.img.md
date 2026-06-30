# Firmware Audit: GL.iNet GL-B3000 Marble / openwrt-b3000-4.5.12-0702-1719852246.img

- Source URL: https://fw.gl-inet.com/firmware/b3000/release/openwrt-b3000-4.5.12-0702-1719852246.img
- Local path: known_firmware/firmware/GL.iNet_GL-B3000_Marble/openwrt-b3000-4.5.12-0702-1719852246.img
- SHA-256: `c486dd37c9217855aa4485a6b488fff4b9f1f23e9fadc8c60a8a4dbcf76c9727`
- Size: 60075923 bytes
- Version: 4.5.12
- Release date: 2024-07-02 00:08:53

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c486dd37c9217855 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
