# Firmware Audit: WGT634U / WGT634U_Firmware_Version_1.4.1.13.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WGT634U/WGT634U%20Firmware%20Version%201.4.1.13.zip
- Local path: known_firmware/firmware/WGT634U/WGT634U_Firmware_Version_1.4.1.13.zip
- SHA-256: `fdf1f2e6f85a223a5eebccb3e3d68c8e83d8580dff172fce3b802df2171aca90`
- Size: 4899071 bytes
- Version: 4.1.13
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, scanf, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/fdf1f2e6f85a223a exited 0: WARNING: Extractor.execute failed to run external extractor 'jefferson -d 'jffs2-root' '%e'': [Errno 2] No such file or directory: 'jefferson', 'jefferson -d 'jffs2-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
