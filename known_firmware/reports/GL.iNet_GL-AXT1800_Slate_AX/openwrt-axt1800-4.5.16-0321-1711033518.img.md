# Firmware Audit: GL.iNet GL-AXT1800 Slate AX / openwrt-axt1800-4.5.16-0321-1711033518.img

- Source URL: https://fw.gl-inet.com/firmware/axt1800/release/openwrt-axt1800-4.5.16-0321-1711033518.img
- Local path: known_firmware/firmware/GL.iNet_GL-AXT1800_Slate_AX/openwrt-axt1800-4.5.16-0321-1711033518.img
- SHA-256: `c516a96fd52d744d64c5dc3f8d58eb3d91a419ae78bf2ed7282690c742507232`
- Size: 50857759 bytes
- Version: 4.5.16
- Release date: 2024-03-21 23:03:45

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, bOa, boA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c516a96fd52d744d exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
