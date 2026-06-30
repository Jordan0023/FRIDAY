# Firmware Audit: GL.iNet GL-X2000 Spitz Plus / openwrt-x2000-4.5.25-0226-1740561614.img

- Source URL: https://fw.gl-inet.com/firmware/x2000/release/openwrt-x2000-4.5.25-0226-1740561614.img
- Local path: known_firmware/firmware/GL.iNet_GL-X2000_Spitz_Plus/openwrt-x2000-4.5.25-0226-1740561614.img
- SHA-256: `dbd2b0c2fdd2ed3b5ea7fc8257562d7ad315c311196b1ae6b184210462b51575`
- Size: 60337158 bytes
- Version: 4.5.25
- Release date: 2025-02-26 16:55:00

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/dbd2b0c2fdd2ed3b exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
