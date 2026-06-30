# Firmware Audit: ASUS 4G-AC86U / Modem_FW_4G-AC86U_LTE_A18.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/4G-AC86U/Modem_FW_4G-AC86U_LTE_A18.zip
- Local path: known_firmware/firmware/ASUS_4G-AC86U/Modem_FW_4G-AC86U_LTE_A18.zip
- SHA-256: `8d7d69497c398d334c452e9f047f6b56a065fd58ec7381ee0c7c0d92724b2509`
- Size: 105640169 bytes
- Version: A18
- Release date: 2022/05/23

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `inetd, telnetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, cgi-bin, httpd`

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

- binwalk -eM --directory known_firmware/extracted/8d7d69497c398d33 exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
