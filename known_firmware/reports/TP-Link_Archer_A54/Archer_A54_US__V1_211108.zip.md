# Firmware Audit: TP-Link Archer A54 / Archer_A54_US__V1_211108.zip

- Source URL: https://static.tp-link.com/upload/firmware/2022/202202/20220209/Archer A54(US)_V1_211108.zip
- Local path: known_firmware/firmware/TP-Link_Archer_A54/Archer_A54_US__V1_211108.zip
- SHA-256: `1a0315ec62087aef0f6166c7689666a7a1ca31ea48a37d49199663a9f42560b2`
- Size: 8100730 bytes
- Version: unknown
- Release date: 2022-02-09

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/1a0315ec62087aef exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/1a0315ec62087aef/_Archer_A54_US__V1_211108.zip.extracted/_Archer_A54v1_US_0.9.1_0.4_up_boot[211108-rel33223].bin.extracted/squashfs-root/etc/passwd -> /var/passwd; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
