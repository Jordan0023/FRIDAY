# Firmware Audit: RAX36S / RAX36S_V1.0.7.54.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX36S/RAX36S_V1.0.7.54.zip
- Local path: known_firmware/firmware/RAX36S/RAX36S_V1.0.7.54.zip
- SHA-256: `502a73b7a1f58628dece59c5b665a0b7e2b974a23f1e3d2c697a79ea1215dc73`
- Size: 60767434 bytes
- Version: 0.7.54
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `bOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/502a73b7a1f58628 exited 0: WARNING: Extractor.execute failed to run external extractor 'yaffshiv --auto --brute-force -f '%e' -d 'yaffs-root'': [Errno 2] No such file or directory: 'yaffshiv', 'yaffshiv --auto --brute-force -f '%e' -d 'yaffs-root'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
