# Firmware Audit: TP-Link Archer GX90 / Archer_GX90_US__V1_231117.zip

- Source URL: https://static.tp-link.com/upload/firmware/2023/202312/20231221/Archer GX90(US)_V1_231117.zip
- Local path: known_firmware/firmware/TP-Link_Archer_GX90/Archer_GX90_US__V1_231117.zip
- SHA-256: `6a07563251fd015beccf65b5603b44865440176c027e5bfac9e50500539eace4`
- Size: 45956909 bytes
- Version: V1.6_1.1.4 Build 20231117
- Release date: 2023-12-21

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `dropbear, telnetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, Boa, boA, cgi-bin, uhttpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, eval, system`

### Outdated crypto/library markers

Old OpenSSL/BusyBox versions may contain known CVEs and should be mapped to package versions.

Evidence: `OpenSSL 1.0.`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6a07563251fd015b exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
