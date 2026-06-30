# Firmware Audit: RAX50V2 / RAX50v2-V1.1.6.38.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX50/RAX50v2-V1.1.6.38.zip
- Local path: known_firmware/firmware/RAX50V2/RAX50v2-V1.1.6.38.zip
- SHA-256: `e25c453743be0dfc92953a4e270b7547297cde5c1ffb27a8a70821b81b94f946`
- Size: 81337988 bytes
- Version: 1.1.6.38
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, Boa, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e25c453743be0dfc exited 0: WARNING: Extractor.execute failed to run external extractor 'tsk_recover -i raw -f ext -a -v '%e' 'ext-root'': [Errno 2] No such file or directory: 'tsk_recover', 'tsk_recover -i raw -f ext -a -v '%e' 'ext-root'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
