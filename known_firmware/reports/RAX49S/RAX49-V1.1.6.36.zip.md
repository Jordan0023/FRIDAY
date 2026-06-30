# Firmware Audit: RAX49S / RAX49-V1.1.6.36.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX49S/RAX49-V1.1.6.36.zip
- Local path: known_firmware/firmware/RAX49S/RAX49-V1.1.6.36.zip
- SHA-256: `91bc3ba6d367a6bdfa42eb5c18a67a22360c141d16413fb9a009794a2c6d345d`
- Size: 81385763 bytes
- Version: 1.1.6.36
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, BoA, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/91bc3ba6d367a6bd exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
