# Firmware Audit: GL.iNet GL-AXT1800 Slate AX / openwrt-axt1800-4.6.2-0709-1720529672.img

- Source URL: https://fw.gl-inet.com/firmware/axt1800/release/openwrt-axt1800-4.6.2-0709-1720529672.img
- Local path: known_firmware/firmware/GL.iNet_GL-AXT1800_Slate_AX/openwrt-axt1800-4.6.2-0709-1720529672.img
- SHA-256: `0102f878608f31e908071bc8335e754b1c70190f50d9449a2a0eb822acb9ff0a`
- Size: 48891679 bytes
- Version: 4.6.2
- Release date: 2024-07-09 20:18:22

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, Boa, boA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0102f878608f31e9 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
