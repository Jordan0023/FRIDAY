# Firmware Audit: RAX49S / RAX49-V1.1.6.38.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX49S/RAX49-V1.1.6.38.zip
- Local path: known_firmware/firmware/RAX49S/RAX49-V1.1.6.38.zip
- SHA-256: `fe7d6c417177572b7a1aad6bf3ebfb679e8cef9f50178d650927f7de06551b9e`
- Size: 81337979 bytes
- Version: 1.1.6.38
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, Boa, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/fe7d6c417177572b exited 0: WARNING: Extractor.execute failed to run external extractor 'tsk_recover -i raw -f ext -a -v '%e' 'ext-root'': [Errno 2] No such file or directory: 'tsk_recover', 'tsk_recover -i raw -f ext -a -v '%e' 'ext-root'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
