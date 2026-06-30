# Firmware Audit: GL.iNet GL-X2000 Spitz Plus / openwrt-x2000-4.5.13-1012-1728745589.img

- Source URL: https://fw.gl-inet.com/firmware/x2000/release/openwrt-x2000-4.5.13-1012-1728745589.img
- Local path: known_firmware/firmware/GL.iNet_GL-X2000_Spitz_Plus/openwrt-x2000-4.5.13-1012-1728745589.img
- SHA-256: `425ade50a81937b2cb4f779ad0c2b8daaed9643db5f15b110b44383e8d470b36`
- Size: 60336749 bytes
- Version: 4.5.13
- Release date: 2024-10-12 22:22:19

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/425ade50a81937b2 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
