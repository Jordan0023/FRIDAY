# Firmware Audit: GL.iNet GL-XE300 Puli / openwrt-xe300-4.0-release10325-0331-1743426136.img

- Source URL: https://fw.gl-inet.com/firmware/xe300/release4/openwrt-xe300-4.0-release10325-0331-1743426136.img
- Local path: known_firmware/firmware/GL.iNet_GL-XE300_Puli/openwrt-xe300-4.0-release10325-0331-1743426136.img
- SHA-256: `4b9ec5d347a3e455ff99e93905d361af4f6fd653379eaf167ddeb6faee24d586`
- Size: 18219008 bytes
- Version: 4.3.25
- Release date: 2025-03-31 21:01:36

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/4b9ec5d347a3e455 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
