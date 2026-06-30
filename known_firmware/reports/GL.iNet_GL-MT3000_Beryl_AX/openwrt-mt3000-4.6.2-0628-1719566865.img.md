# Firmware Audit: GL.iNet GL-MT3000 Beryl AX / openwrt-mt3000-4.6.2-0628-1719566865.img

- Source URL: https://fw.gl-inet.com/firmware/mt3000/release/openwrt-mt3000-4.6.2-0628-1719566865.img
- Local path: known_firmware/firmware/GL.iNet_GL-MT3000_Beryl_AX/openwrt-mt3000-4.6.2-0628-1719566865.img
- SHA-256: `577000c83e7e8bd6ee230690efdd3da9c9c0afd451eebe28998a1d39b334742c`
- Size: 50462720 bytes
- Version: 4.6.2
- Release date: 2024-06-28 16:56:13

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, bOa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/577000c83e7e8bd6 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
