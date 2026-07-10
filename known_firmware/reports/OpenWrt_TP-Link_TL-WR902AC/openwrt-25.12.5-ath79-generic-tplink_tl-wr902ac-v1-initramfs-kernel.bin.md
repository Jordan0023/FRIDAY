# Firmware Audit: OpenWrt TP-Link TL-WR902AC / openwrt-25.12.5-ath79-generic-tplink_tl-wr902ac-v1-initramfs-kernel.bin

- Source URL: https://downloads.openwrt.org/releases/25.12.5/targets/ath79/generic/openwrt-25.12.5-ath79-generic-tplink_tl-wr902ac-v1-initramfs-kernel.bin
- Local path: known_firmware/firmware/OpenWrt_TP-Link_TL-WR902AC/openwrt-25.12.5-ath79-generic-tplink_tl-wr902ac-v1-initramfs-kernel.bin
- SHA-256: `b7415497c6cd48e0e7ea829f6485e126adfccacdd070fe9dc054fefab8c9d9d2`
- Size: 7001957 bytes
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

Evidence: `cgi-bin, httpd, uHTTPd, uhttpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `SYSTEM, System, eval, popen, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat, strcpy`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b7415497c6cd48e0 exited 0: WARNING: Extractor.execute failed to run external extractor 'jefferson -d 'jffs2-root' '%e'': [Errno 2] No such file or directory: 'jefferson', 'jefferson -d 'jffs2-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
