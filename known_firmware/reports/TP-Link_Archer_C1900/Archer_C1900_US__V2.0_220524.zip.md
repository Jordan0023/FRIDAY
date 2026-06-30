# Firmware Audit: TP-Link Archer C1900 / Archer_C1900_US__V2.0_220524.zip

- Source URL: https://static.tp-link.com/upload/firmware/2022/202209/20220913/Archer C1900(US)_V2.0_220524.zip
- Local path: known_firmware/firmware/TP-Link_Archer_C1900/Archer_C1900_US__V2.0_220524.zip
- SHA-256: `28c817eb37949c36275c3eb4da75a2e910fe65209a230ae51c87aafd6c351541`
- Size: 15150976 bytes
- Version: V2_1.0.1 Build 20220524
- Release date: 2022-09-13

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `dropbear`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, cgi-bin, httpd, uhttpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/28c817eb37949c36 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/28c817eb37949c36/_Archer_C1900_US__V2.0_220524.zip.extracted/Archer C1900(US)_V2.0_220524/_C1900v2_us-up-1.0.1 Build 20220524 rel.40737_2022-05-24_11.20.12.bin.extracted/squashfs-root/etc/ppp/resolv.conf -> /tmp/resolv.conf.ppp; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
