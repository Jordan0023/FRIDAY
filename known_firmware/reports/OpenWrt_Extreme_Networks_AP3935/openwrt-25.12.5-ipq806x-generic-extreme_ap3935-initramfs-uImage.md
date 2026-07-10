# Firmware Audit: OpenWrt Extreme Networks AP3935 / openwrt-25.12.5-ipq806x-generic-extreme_ap3935-initramfs-uImage

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ipq806x/generic/openwrt-25.12.5-ipq806x-generic-extreme_ap3935-initramfs-uImage
- Local path: known_firmware/firmware/OpenWrt_Extreme_Networks_AP3935/openwrt-25.12.5-ipq806x-generic-extreme_ap3935-initramfs-uImage
- SHA-256: `57774d69a4a3d32318e35a1aab535e66a4d455c41a0229e83878f9fb36b43248`
- Size: 7835933 bytes
- Version: 25.12.5
- Release date: 2026-06-29

## Static Findings

### Private keys or certificates bundled in firmware

Embedded private keys/certificates can allow credential reuse or impersonation if shared across devices.

Evidence: `-----BEGIN CERTIFICATE-----, -----BEGIN EC PRIVATE KEY-----, -----BEGIN PRIVATE KEY-----, -----BEGIN RSA PRIVATE KEY-----`

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password, password, token`

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `DROPBEAR, Dropbear, dropbear, telnetd`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, cgi-bin, httpd, uHTTPd, uhttpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `SYSTEM, System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/57774d69a4a3d323 exited 0: WARNING: Extractor.execute failed to run external extractor 'jefferson -d 'jffs2-root' '%e'': [Errno 2] No such file or directory: 'jefferson', 'jefferson -d 'jffs2-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
