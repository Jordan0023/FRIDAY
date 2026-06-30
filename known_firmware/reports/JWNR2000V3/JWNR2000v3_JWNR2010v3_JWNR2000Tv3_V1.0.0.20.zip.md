# Firmware Audit: JWNR2000V3 / JWNR2000v3_JWNR2010v3_JWNR2000Tv3_V1.0.0.20.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/JWNR2010V3/JWNR2000v3_JWNR2010v3_JWNR2000Tv3_V1.0.0.20.zip
- Local path: known_firmware/firmware/JWNR2000V3/JWNR2000v3_JWNR2010v3_JWNR2000Tv3_V1.0.0.20.zip
- SHA-256: `e4dd7281917f29eab8ff7b33cafa518e9bd21562ccdadf342da2b969f65c9821`
- Size: 3620046 bytes
- Version: 0.0.20
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password, password`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `inetd, telnetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `cgi-bin`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `SYSTEM, System, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e4dd7281917f29ea exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/e4dd7281917f29ea/_JWNR2000v3_JWNR2010v3_JWNR2000Tv3_V1.0.0.20.zip.extracted/_jwnr2010-jwnr2000tv3-jwnr2000v3-v1.0.0.20.img.extracted/squashfs-root/etc/ppp/chap-secrets -> /var/ppp/chap-secrets; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
