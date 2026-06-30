# Firmware Audit: TP-Link Archer A54 / Archer_A54_US__V1_230810.zip

- Source URL: https://static.tp-link.com/upload/firmware/2023/202310/20231018/Archer A54(US)_V1_230810.zip
- Local path: known_firmware/firmware/TP-Link_Archer_A54/Archer_A54_US__V1_230810.zip
- SHA-256: `8339a402ce005ea4610a3f003a6e17aa2c59ace211e13200f16e03bcb874bc57`
- Size: 8018596 bytes
- Version: unknown
- Release date: 2023-10-18

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/8339a402ce005ea4 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/8339a402ce005ea4/_Archer_A54_US__V1_230810.zip.extracted/_Archer_A54v1_US_0.9.1_0.5_up_boot[230810-rel38522].bin.extracted/squashfs-root/etc/passwd -> /var/passwd; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
