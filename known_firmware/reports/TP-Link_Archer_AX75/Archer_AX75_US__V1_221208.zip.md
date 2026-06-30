# Firmware Audit: TP-Link Archer AX75 / Archer_AX75_US__V1_221208.zip

- Source URL: https://static.tp-link.com/upload/firmware/2023/202305/20230519/Archer AX75(US)_V1_221208.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX75/Archer_AX75_US__V1_221208.zip
- SHA-256: `9e5ab729033928945cf2774a5bb5c4bd55d5d10a0c4c520b2935a042b702867c`
- Size: 38771290 bytes
- Version: V1.6_1.1.1 Build 20221208
- Release date: 2023-05-19

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA, bOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9e5ab72903392894 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/9e5ab72903392894/_Archer_AX75_US__V1_221208.zip.extracted/Archer AX75(US)_V1_221208/_ax75v1-up-ver1-1-1-P1[20221208-rel65555]_signed_2022-12-08_19.51.45.bin.extracted/squashfs-root/etc/ppp/resolv.conf -> /tmp/resolv.conf.ppp; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
