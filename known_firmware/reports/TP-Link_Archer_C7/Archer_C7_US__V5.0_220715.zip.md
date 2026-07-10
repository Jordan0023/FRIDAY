# Firmware Audit: TP-Link Archer C7 / Archer_C7_US__V5.0_220715.zip

- Source URL: https://static.tp-link.com/upload/firmware/2022/202211/20221108/Archer C7(US)_V5.0_220715.zip
- Local path: known_firmware/firmware/TP-Link_Archer_C7/Archer_C7_US__V5.0_220715.zip
- SHA-256: `5d322bba6e0531fc76387a5cc22e7b2ebf3288835dfb69d6a798d7b8b4b87362`
- Size: 16398791 bytes
- Version: V5.8_1.2.1 Build 20220715
- Release date: 2022-11-08

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, Boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/5d322bba6e0531fc exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/5d322bba6e0531fc/_Archer_C7_US__V5.0_220715.zip.extracted/Archer C7(US)_V5.0_220715/_c7v5_us-up-ver1-2-1-P1[20220715-rel19099]_2022-07-15_17.44.43.bin.extracted/squashfs-root/etc/ppp/resolv.conf -> /tmp/resolv.conf.ppp; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
