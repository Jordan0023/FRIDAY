# Firmware Audit: TP-Link Archer C6 / Archer_C6_US__V2_230830.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202509/20250910/Archer C6(US)_V2_230830.zip
- Local path: known_firmware/firmware/TP-Link_Archer_C6/Archer_C6_US__V2_230830.zip
- SHA-256: `88ee897b905baad84571273cdcb05e76f477b21601da7619e30e1b706e370c9b`
- Size: 14715244 bytes
- Version: V2.80_1.1.10 Build 20230830
- Release date: 2025-09-10

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/88ee897b905baad8 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/88ee897b905baad8/_Archer_C6_US__V2_230830.zip.extracted/_ArcherC6v2_us_tw_c6us-up-ver1-1-10-P1[20230830-rel69433].bin.extracted/squashfs-root/etc/ppp/resolv.conf -> /tmp/resolv.conf.ppp; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
