# Firmware Audit: RAX36S / RAX36S_V1.0.6.52.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX36S/RAX36S_V1.0.6.52.zip
- Local path: known_firmware/firmware/RAX36S/RAX36S_V1.0.6.52.zip
- SHA-256: `915e4b35ee9b59a769126f4212674bde7711ba5c84d229de8c898a11d6324a82`
- Size: 121499355 bytes
- Version: 0.6.52
- Release date: unknown

## Static Findings

### Private keys or certificates bundled in firmware

Embedded private keys/certificates can allow credential reuse or impersonation if shared across devices.

Evidence: `-----BEGIN CERTIFICATE-----`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `telnetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `cgi-bin, lighttpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `SYSTEM, System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/915e4b35ee9b59a7 stopped: extraction exceeded 60000 MB

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
