# Firmware Audit: TP-Link Festa FR205 / Festa_FR205_UN__v1_V1.20_1.0.1_Build_20240522.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202406/20240621/Festa FR205(UN)_v1_V1.20_1.0.1 Build 20240522.zip
- Local path: known_firmware/firmware/TP-Link_Festa_FR205/Festa_FR205_UN__v1_V1.20_1.0.1_Build_20240522.zip
- SHA-256: `6175642a187049ccb64fc6e7c6a32be86cc0d8d21ebd608ccdc91844fd3511ff`
- Size: 20893908 bytes
- Version: V1.6_1.0.1 Build 20240522
- Release date: 2024-06-21

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, boa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6175642a187049cc exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/6175642a187049cc/_Festa_FR205_UN__v1_V1.20_1.0.1_Build_20240522.zip.extracted/_Festa_FR205_un_1.0.1_20240522-rel75860_common_v1_up_2024-05-22_21.31.54.bin.extracted/squashfs-root-0/usr/sbin/rmmod -> /usr/sbin/kmodloader; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
