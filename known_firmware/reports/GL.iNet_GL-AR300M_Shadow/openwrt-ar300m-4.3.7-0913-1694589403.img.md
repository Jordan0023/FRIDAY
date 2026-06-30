# Firmware Audit: GL.iNet GL-AR300M Shadow / openwrt-ar300m-4.3.7-0913-1694589403.img

- Source URL: https://fw.gl-inet.com/firmware/ar300m/nand/release4/openwrt-ar300m-4.3.7-0913-1694589403.img
- Local path: known_firmware/firmware/GL.iNet_GL-AR300M_Shadow/openwrt-ar300m-4.3.7-0913-1694589403.img
- SHA-256: `3b0779dfa3bef2f4a22147d91bc43df48573728799cd511b037b18a407709be6`
- Size: 17828154 bytes
- Version: 4.3.7
- Release date: 2023-09-13 15:15:37

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3b0779dfa3bef2f4 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
