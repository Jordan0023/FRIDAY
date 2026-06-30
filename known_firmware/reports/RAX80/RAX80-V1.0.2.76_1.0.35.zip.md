# Firmware Audit: RAX80 / RAX80-V1.0.2.76_1.0.35.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX80/RAX80-V1.0.2.76_1.0.35.zip
- Local path: known_firmware/firmware/RAX80/RAX80-V1.0.2.76_1.0.35.zip
- SHA-256: `73d993d911fd730364266fe760539dc0cd65c582ad9ae028ed38e00545d3a84e`
- Size: 50697887 bytes
- Version: 1.0.2.76_1.0.35
- Release date: unknown

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `SSHD`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, Boa, bOA, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/73d993d911fd7303 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
