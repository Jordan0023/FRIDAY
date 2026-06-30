# Firmware Audit: TP-Link Archer A54 / Archer_A54_US__V1_240816.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202410/20241028/Archer A54(US)_V1_240816.zip
- Local path: known_firmware/firmware/TP-Link_Archer_A54/Archer_A54_US__V1_240816.zip
- SHA-256: `f82b89e3970698b74938035bcedeea707727fb7c03d7d46b5b542cc458d2d804`
- Size: 8331879 bytes
- Version: unknown
- Release date: 2024-10-28

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/f82b89e3970698b7 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/f82b89e3970698b7/_Archer_A54_US__V1_240816.zip.extracted/_Archer_A54v1_US_0.9.1_0.5_up_boot[240816-rel42750]_2024-08-16_15.21.23.bin.extracted/squashfs-root-0/etc/passwd -> /var/passwd; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
