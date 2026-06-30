# Firmware Audit: RAX43 / RAX43-V1.0.17.144.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX43/RAX43-V1.0.17.144.zip
- Local path: known_firmware/firmware/RAX43/RAX43-V1.0.17.144.zip
- SHA-256: `67856c9f7ad8285ccf0904ffea22fbb0c9ba573d3940231746064c901631ec4b`
- Size: 81321666 bytes
- Version: 1.0.17.144
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, Boa, bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/67856c9f7ad8285c exited 0: WARNING: Extractor.execute failed to run external extractor 'tsk_recover -i raw -f ext -a -v '%e' 'ext-root'': [Errno 2] No such file or directory: 'tsk_recover', 'tsk_recover -i raw -f ext -a -v '%e' 'ext-root'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
