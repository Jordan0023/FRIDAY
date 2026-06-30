# Firmware Audit: RAX48 / RAX48-V1.0.17.144.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX48/RAX48-V1.0.17.144.zip
- Local path: known_firmware/firmware/RAX48/RAX48-V1.0.17.144.zip
- SHA-256: `18e22c0612dda7c0d57ef06cd17ccce8f1b6a8f2c2119c564af690421b714141`
- Size: 81321664 bytes
- Version: 1.0.17.144
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, Boa, bOa, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/18e22c0612dda7c0 exited 0: WARNING: Extractor.execute failed to run external extractor 'tsk_recover -i raw -f ext -a -v '%e' 'ext-root'': [Errno 2] No such file or directory: 'tsk_recover', 'tsk_recover -i raw -f ext -a -v '%e' 'ext-root'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
