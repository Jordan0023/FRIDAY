# Firmware Audit: RAX41V2 / RAX41v2-V1.1.6.38.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX41/RAX41v2-V1.1.6.38.zip
- Local path: known_firmware/firmware/RAX41V2/RAX41v2-V1.1.6.38.zip
- SHA-256: `c52efe4a322909d7806b29863b601ad4aa4b6b608d033572b1f0c23b7e63eae6`
- Size: 81338011 bytes
- Version: 1.1.6.38
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA, Boa, bOa`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/c52efe4a322909d7 exited 0: WARNING: Extractor.execute failed to run external extractor 'tsk_recover -i raw -f ext -a -v '%e' 'ext-root'': [Errno 2] No such file or directory: 'tsk_recover', 'tsk_recover -i raw -f ext -a -v '%e' 'ext-root'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
