# Firmware Audit: TP-Link Archer AX75 / Archer_AX75_US__V1_230606.zip

- Source URL: https://static.tp-link.com/upload/firmware/2023/202307/20230718/Archer AX75(US)_V1_230606.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX75/Archer_AX75_US__V1_230606.zip
- SHA-256: `6fde710d3694eeb5474153a9e2fc6357bc7616c2b2954955293ec3d729fb346d`
- Size: 40033081 bytes
- Version: V1.6_1.1.2 Build 20230606
- Release date: 2023-07-18

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `PwD`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, BoA, bOA, bOa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `EVal`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6fde710d3694eeb5 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/6fde710d3694eeb5/_Archer_AX75_US__V1_230606.zip.extracted/_ax75v1-up-ver1-1-2-P1[20230606-rel1786]_nosign_2023-06-07_11.28.40.bin.extracted/squashfs-root/etc/ppp/resolv.conf -> /tmp/resolv.conf.ppp; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
