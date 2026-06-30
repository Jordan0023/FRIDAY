# Firmware Audit: TP-Link Archer AX75 / Archer_AX75_US__V1_220531.zip

- Source URL: https://static.tp-link.com/upload/firmware/2022/202207/20220713/Archer AX75(US)_V1_220531.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AX75/Archer_AX75_US__V1_220531.zip
- SHA-256: `6c87975cf07b2caabbd677a4fbda921e7a879b25f7bede342247fad1e5dcb019`
- Size: 38591328 bytes
- Version: V1.6_1.1.0 Build 20220531
- Release date: 2022-07-13

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BoA, bOA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/6c87975cf07b2caa exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/6c87975cf07b2caa/_Archer_AX75_US__V1_220531.zip.extracted/Archer AX75(US)_V1_220531/_ax75v1-up-ver1-1-0-P1[20220531-rel45673]_nosign.bin.extracted/squashfs-root/etc/ppp/resolv.conf -> /tmp/resolv.conf.ppp; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
