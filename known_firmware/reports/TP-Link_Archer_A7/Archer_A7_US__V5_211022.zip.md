# Firmware Audit: TP-Link Archer A7 / Archer_A7_US__V5_211022.zip

- Source URL: https://static.tp-link.com/upload/firmware/2021/202110/20211029/Archer A7(US)_V5_211022.zip
- Local path: known_firmware/firmware/TP-Link_Archer_A7/Archer_A7_US__V5_211022.zip
- SHA-256: `1331364f46c13f2ac0daf721d4e554cfd0cd1073e9ebf4706b016d203d88e690`
- Size: 16078101 bytes
- Version: unknown
- Release date: 2021-10-29

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1331364f46c13f2a exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/1331364f46c13f2a/_Archer_A7_US__V5_211022.zip.extracted/Archer A7(US)_V5_211022/_a7v5-up-ver1-1-4-P1[20211022-rel58866].bin.extracted/squashfs-root/etc/ppp/resolv.conf -> /tmp/resolv.conf.ppp; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
