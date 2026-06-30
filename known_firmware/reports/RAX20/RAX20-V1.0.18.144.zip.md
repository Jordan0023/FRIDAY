# Firmware Audit: RAX20 / RAX20-V1.0.18.144.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX20/RAX20-V1.0.18.144.zip
- Local path: known_firmware/firmware/RAX20/RAX20-V1.0.18.144.zip
- SHA-256: `d3de4f61e084ac5f1067c1986d332c16034725177469872d9c5154ddf3224c70`
- Size: 81640954 bytes
- Version: 1.0.18.144
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `password`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, BoA, Boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d3de4f61e084ac5f exited 0: WARNING: Extractor.execute failed to run external extractor 'tsk_recover -i raw -f ext -a -v '%e' 'ext-root'': [Errno 2] No such file or directory: 'tsk_recover', 'tsk_recover -i raw -f ext -a -v '%e' 'ext-root'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
