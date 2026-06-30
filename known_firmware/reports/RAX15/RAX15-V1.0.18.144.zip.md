# Firmware Audit: RAX15 / RAX15-V1.0.18.144.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX15/RAX15-V1.0.18.144.zip
- Local path: known_firmware/firmware/RAX15/RAX15-V1.0.18.144.zip
- SHA-256: `45d7c16140aa3d9e574f57977ce8f14e2547900ea8eac70803fa79fed7496a1c`
- Size: 81640971 bytes
- Version: 1.0.18.144
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/45d7c16140aa3d9e exited 0: WARNING: Extractor.execute failed to run external extractor 'tsk_recover -i raw -f ext -a -v '%e' 'ext-root'': [Errno 2] No such file or directory: 'tsk_recover', 'tsk_recover -i raw -f ext -a -v '%e' 'ext-root'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
