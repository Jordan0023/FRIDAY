# Firmware Audit: ASUS 4G-AC86U / Modem_FW_4G-AC86U_LTE_A21_004.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/4G-AC86U/Modem_FW_4G-AC86U_LTE_A21_004.zip
- Local path: known_firmware/firmware/ASUS_4G-AC86U/Modem_FW_4G-AC86U_LTE_A21_004.zip
- SHA-256: `874dc79611ffa0dea13009d0c8f5b1227c8697a4f0510fababe13b0ed245ca25`
- Size: 106235255 bytes
- Version: A21_004
- Release date: 2021/05/17

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `inetd, telnetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa, cgi-bin, httpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `/bin/ash, /bin/sh, SYSTEM, System, eval, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `scanf, strcat, strcpy`

### Outdated crypto/library markers

Old OpenSSL/BusyBox versions may contain known CVEs and should be mapped to package versions.

Evidence: `BusyBox v1.23`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/874dc79611ffa0de exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
