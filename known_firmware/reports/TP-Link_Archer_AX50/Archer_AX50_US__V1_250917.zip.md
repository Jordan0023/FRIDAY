# Firmware Audit: TP-Link Archer AX50 / Archer_AX50_US__V1_250917.zip

- Source URL: https://static.tp-link.com/upload/firmware/2025/202509/20250930/Archer AX50(US)_V1_250917.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX50/Archer_AX50_US__V1_250917.zip
- SHA-256: `e4b074697db179c56d5f926236101922bedd6cad76c08874005cbf43ab90f6e1`
- Size: 30881049 bytes
- Version: V1.8_1.1.1 Build 20250917
- Release date: 2025-09-30

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, bOA, bOa`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e4b074697db179c5 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/e4b074697db179c5/_Archer_AX50_US__V1_250917.zip.extracted/_ax50v1_intel-up-ver1-1-1-P1[20250917-rel63889]_sign.bin.extracted/squashfs-root/opt/lantiq/bin/drv_event_logger.ko -> /usr/lib/modules/3.10.104/drv_event_logger.ko; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
