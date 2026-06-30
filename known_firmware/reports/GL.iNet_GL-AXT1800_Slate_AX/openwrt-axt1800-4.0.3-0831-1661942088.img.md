# Firmware Audit: GL.iNet GL-AXT1800 Slate AX / openwrt-axt1800-4.0.3-0831-1661942088.img

- Source URL: https://fw.gl-inet.com/firmware/axt1800/release/openwrt-axt1800-4.0.3-0831-1661942088.img
- Local path: known_firmware/firmware/GL.iNet_GL-AXT1800_Slate_AX/openwrt-axt1800-4.0.3-0831-1661942088.img
- SHA-256: `3a72d3db1743e78b002fb8f0228d8f41f0ded8ed310679f2eaee8717bf53ae4c`
- Size: 51644191 bytes
- Version: 4.0.3
- Release date: 2022-08-31 18:34:48

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `ssHD`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, Boa, bOA, bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3a72d3db1743e78b exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
