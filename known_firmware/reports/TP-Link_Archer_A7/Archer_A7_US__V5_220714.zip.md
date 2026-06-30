# Firmware Audit: TP-Link Archer A7 / Archer_A7_US__V5_220714.zip

- Source URL: https://static.tp-link.com/upload/firmware/2022/202211/20221108/Archer A7(US)_V5_220714.zip
- Local path: known_firmware/firmware/TP-Link_Archer_A7/Archer_A7_US__V5_220714.zip
- SHA-256: `31db326b2bcb8e0b4bbf05a8b1db8ae8e0756cec6805205371aacbbcf76459ee`
- Size: 16349088 bytes
- Version: V5_1.2.1 Build 20220714
- Release date: 2022-11-08

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/31db326b2bcb8e0b exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/31db326b2bcb8e0b/_Archer_A7_US__V5_220714.zip.extracted/Archer A7(US)_V5_220714/_a7v5_us-up-ver1-2-1-P1[20220714-rel75573].bin.extracted/squashfs-root/etc/ppp/resolv.conf -> /tmp/resolv.conf.ppp; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
