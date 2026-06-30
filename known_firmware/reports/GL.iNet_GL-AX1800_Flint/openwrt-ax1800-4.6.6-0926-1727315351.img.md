# Firmware Audit: GL.iNet GL-AX1800 Flint / openwrt-ax1800-4.6.6-0926-1727315351.img

- Source URL: https://fw.gl-inet.com/firmware/ax1800/v4/openwrt-ax1800-4.6.6-0926-1727315351.img
- Local path: known_firmware/firmware/GL.iNet_GL-AX1800_Flint/openwrt-ax1800-4.6.6-0926-1727315351.img
- SHA-256: `d53c67cd66bcb41a96d8137c29230a4fd0bf9bfb567315fe0005bae71390f552`
- Size: 49023682 bytes
- Version: 4.6.6
- Release date: 2024-09-26 09:23:31

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, Boa, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d53c67cd66bcb41a exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
