# Firmware Audit: RAX41 / RAX41-V1.0.17.144.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX41/RAX41-V1.0.17.144.zip
- Local path: known_firmware/firmware/RAX41/RAX41-V1.0.17.144.zip
- SHA-256: `dfb0522135056719f4d8bf9d33a9cbe840c6c17e9e050d50637af53ca61d0c93`
- Size: 81321682 bytes
- Version: 1.0.17.144
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, bOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/dfb0522135056719 exited 0: WARNING: Extractor.execute failed to run external extractor 'tsk_recover -i raw -f ext -a -v '%e' 'ext-root'': [Errno 2] No such file or directory: 'tsk_recover', 'tsk_recover -i raw -f ext -a -v '%e' 'ext-root'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
