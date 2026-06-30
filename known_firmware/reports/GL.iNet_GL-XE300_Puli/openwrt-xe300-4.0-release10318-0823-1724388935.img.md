# Firmware Audit: GL.iNet GL-XE300 Puli / openwrt-xe300-4.0-release10318-0823-1724388935.img

- Source URL: https://fw.gl-inet.com/firmware/xe300/release4/openwrt-xe300-4.0-release10318-0823-1724388935.img
- Local path: known_firmware/firmware/GL.iNet_GL-XE300_Puli/openwrt-xe300-4.0-release10318-0823-1724388935.img
- SHA-256: `49383b1937229c4f35b1c5e7048cc50851b6163ff14118f54c7285225d20e045`
- Size: 18219008 bytes
- Version: 4.3.18
- Release date: 2024-08-23 12:53:54

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/49383b1937229c4f exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
