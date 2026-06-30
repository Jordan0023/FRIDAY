# Firmware Audit: WNR834BV1 / WNR834B_Firmware_Version_1.0.4.2__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR834Bv1/WNR834B%20Firmware%20Version%201.0.4.2%20(North%20America).zip
- Local path: known_firmware/firmware/WNR834BV1/WNR834B_Firmware_Version_1.0.4.2__North_America_.zip
- SHA-256: `249cc19ecc91cb6293ce13920903b854a090a803d588c4d47c86382aff1ee86b`
- Size: 3218251 bytes
- Version: 0.4.2__North_America_
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `httpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/249cc19ecc91cb62 exited 0: WARNING: Extractor.execute failed to run external extractor 'cramfsswap '%e' '%e.swap' && cramfsck -x 'cramfs-root' '%e.swap'': [Errno 2] No such file or directory: 'cramfsswap', 'cramfsswap '%e' '%e.swap' && cramfsck -x 'cramfs-root' '%e.swap'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
