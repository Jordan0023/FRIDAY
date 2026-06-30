# Firmware Audit: GL.iNet GL-XE300 Puli / openwrt-xe300-4.0-release30316-0227-1709031323.img

- Source URL: https://fw.gl-inet.com/firmware/xe300/release4/openwrt-xe300-4.0-release30316-0227-1709031323.img
- Local path: known_firmware/firmware/GL.iNet_GL-XE300_Puli/openwrt-xe300-4.0-release30316-0227-1709031323.img
- SHA-256: `b14d3e15309bc81496847dadaa591684f7aeb2635160569781680589f2e2160f`
- Size: 18612224 bytes
- Version: 4.3.16
- Release date: 2024-02-27 18:53:43

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b14d3e15309bc814 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
