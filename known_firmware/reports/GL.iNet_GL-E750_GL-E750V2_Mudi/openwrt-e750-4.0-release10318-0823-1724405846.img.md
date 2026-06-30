# Firmware Audit: GL.iNet GL-E750/GL-E750V2 Mudi / openwrt-e750-4.0-release10318-0823-1724405846.img

- Source URL: https://fw.gl-inet.com/firmware/e750/release4/openwrt-e750-4.0-release10318-0823-1724405846.img
- Local path: known_firmware/firmware/GL.iNet_GL-E750_GL-E750V2_Mudi/openwrt-e750-4.0-release10318-0823-1724405846.img
- SHA-256: `32f502071b18c5f043b04dc63c810b34f3df77abb2ba037de73a1cfc4eb907b8`
- Size: 20840448 bytes
- Version: 4.3.18
- Release date: 2024-08-23 17:35:14

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/32f502071b18c5f0 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
