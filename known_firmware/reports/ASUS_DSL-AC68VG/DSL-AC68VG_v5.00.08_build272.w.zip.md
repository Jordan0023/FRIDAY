# Firmware Audit: ASUS DSL-AC68VG / DSL-AC68VG_v5.00.08_build272.w.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-AC68VG/DSL-AC68VG_v5.00.08_build272.w.zip
- Local path: known_firmware/firmware/ASUS_DSL-AC68VG/DSL-AC68VG_v5.00.08_build272.w.zip
- SHA-256: `cb14cb7ca1e2f0cf5ef2ba4dd57f89323ebffed8483596319af3fb5d0a587eaf`
- Size: 46231486 bytes
- Version: 5.00.08_build272
- Release date: 2018/10/16

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `SSHd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/cb14cb7ca1e2f0cf exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
