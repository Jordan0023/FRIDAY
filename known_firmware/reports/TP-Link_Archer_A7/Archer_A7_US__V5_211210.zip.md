# Firmware Audit: TP-Link Archer A7 / Archer_A7_US__V5_211210.zip

- Source URL: https://static.tp-link.com/upload/firmware/2022/202205/20220510/Archer A7(US)_V5_211210.zip
- Local path: known_firmware/firmware/TP-Link_Archer_A7/Archer_A7_US__V5_211210.zip
- SHA-256: `9b7d09eaa54821b329b5d9e2e127e3b24648b4e83f3d52255bab019975837b44`
- Size: 16078736 bytes
- Version: unknown
- Release date: 2022-05-10

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, Boa, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9b7d09eaa54821b3 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/9b7d09eaa54821b3/_Archer_A7_US__V5_211210.zip.extracted/Archer A7(US)_V5_211210/_a7v5_up-ver1-2-0-P1[20211210-rel56314].bin.extracted/squashfs-root/etc/ppp/resolv.conf -> /tmp/resolv.conf.ppp; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
