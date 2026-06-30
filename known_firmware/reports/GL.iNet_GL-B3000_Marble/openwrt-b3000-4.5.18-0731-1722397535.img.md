# Firmware Audit: GL.iNet GL-B3000 Marble / openwrt-b3000-4.5.18-0731-1722397535.img

- Source URL: https://fw.gl-inet.com/firmware/b3000/release/openwrt-b3000-4.5.18-0731-1722397535.img
- Local path: known_firmware/firmware/GL.iNet_GL-B3000_Marble/openwrt-b3000-4.5.18-0731-1722397535.img
- SHA-256: `c2bc7ef1b3063bda9cac16eccd2f041f620b5d32ca8975be2a1b77ecb5c50b30`
- Size: 60077741 bytes
- Version: 4.5.18
- Release date: 2024-07-31 11:03:34

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c2bc7ef1b3063bda exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
