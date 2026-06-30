# Firmware Audit: GL.iNet GL-XE300 Puli / openwrt-xe300-4.0-release70307-1222-1703233794.img

- Source URL: https://fw.gl-inet.com/firmware/xe300/release4/openwrt-xe300-4.0-release70307-1222-1703233794.img
- Local path: known_firmware/firmware/GL.iNet_GL-XE300_Puli/openwrt-xe300-4.0-release70307-1222-1703233794.img
- SHA-256: `8241a9c308122e7a615ed593fb9919321ee0a866e0e6c5af7a7f229518051f5f`
- Size: 19140695 bytes
- Version: 4.3.7
- Release date: 2023-12-22 16:28:41

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/8241a9c308122e7a exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
