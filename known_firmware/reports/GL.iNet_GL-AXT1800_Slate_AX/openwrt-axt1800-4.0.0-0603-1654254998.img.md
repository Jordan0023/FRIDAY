# Firmware Audit: GL.iNet GL-AXT1800 Slate AX / openwrt-axt1800-4.0.0-0603-1654254998.img

- Source URL: https://fw.gl-inet.com/firmware/axt1800/release/openwrt-axt1800-4.0.0-0603-1654254998.img
- Local path: known_firmware/firmware/GL.iNet_GL-AXT1800_Slate_AX/openwrt-axt1800-4.0.0-0603-1654254998.img
- SHA-256: `d3e7f4cad4557f5ab9c110a7e249d8ecabab69f46f4f99ac18912a710163de2b`
- Size: 50857759 bytes
- Version: 4.0.0
- Release date: 2022-06-03 19:16:38

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, Boa, bOA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d3e7f4cad4557f5a exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
