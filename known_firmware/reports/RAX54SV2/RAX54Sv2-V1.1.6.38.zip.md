# Firmware Audit: RAX54SV2 / RAX54Sv2-V1.1.6.38.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX54S/RAX54Sv2-V1.1.6.38.zip
- Local path: known_firmware/firmware/RAX54SV2/RAX54Sv2-V1.1.6.38.zip
- SHA-256: `c9b1ed79f8f766b583969f1a2cd3f849a8d788f7053a0d845c39db425ef56110`
- Size: 81337991 bytes
- Version: 1.1.6.38
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, Boa, bOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `eval`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c9b1ed79f8f766b5 exited 0: WARNING: Extractor.execute failed to run external extractor 'tsk_recover -i raw -f ext -a -v '%e' 'ext-root'': [Errno 2] No such file or directory: 'tsk_recover', 'tsk_recover -i raw -f ext -a -v '%e' 'ext-root'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
