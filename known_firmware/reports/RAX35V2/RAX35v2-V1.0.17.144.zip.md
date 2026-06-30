# Firmware Audit: RAX35V2 / RAX35v2-V1.0.17.144.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX35v2/RAX35v2-V1.0.17.144.zip
- Local path: known_firmware/firmware/RAX35V2/RAX35v2-V1.0.17.144.zip
- SHA-256: `1f7f7da9d0b7234556bcff3e41ab3dd1a0a60071f307652f3d0efc0f60c39245`
- Size: 81321678 bytes
- Version: 1.0.17.144
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa, bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1f7f7da9d0b72345 exited 0: WARNING: Extractor.execute failed to run external extractor 'tsk_recover -i raw -f ext -a -v '%e' 'ext-root'': [Errno 2] No such file or directory: 'tsk_recover', 'tsk_recover -i raw -f ext -a -v '%e' 'ext-root'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
