# Firmware Audit: RAX42V2 / RAX42v2-V1.1.6.38.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX42/RAX42v2-V1.1.6.38.zip
- Local path: known_firmware/firmware/RAX42V2/RAX42v2-V1.1.6.38.zip
- SHA-256: `e6f2fe38e6ad0fa00eb6602f5b1925a7b0710c2f160ef2ab2c9f311ae6875bf8`
- Size: 81338014 bytes
- Version: 1.1.6.38
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, Boa, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e6f2fe38e6ad0fa0 exited 0: WARNING: Extractor.execute failed to run external extractor 'tsk_recover -i raw -f ext -a -v '%e' 'ext-root'': [Errno 2] No such file or directory: 'tsk_recover', 'tsk_recover -i raw -f ext -a -v '%e' 'ext-root'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
