# Firmware Audit: RAX45 / RAX45-V1.0.17.144.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX45/RAX45-V1.0.17.144.zip
- Local path: known_firmware/firmware/RAX45/RAX45-V1.0.17.144.zip
- SHA-256: `fdb8abca896d83b5dffb568b2ea89b29c23b3f164c9ebded71b662723fe5097c`
- Size: 81321668 bytes
- Version: 1.0.17.144
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, Boa, bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/fdb8abca896d83b5 exited 0: WARNING: Extractor.execute failed to run external extractor 'tsk_recover -i raw -f ext -a -v '%e' 'ext-root'': [Errno 2] No such file or directory: 'tsk_recover', 'tsk_recover -i raw -f ext -a -v '%e' 'ext-root'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
