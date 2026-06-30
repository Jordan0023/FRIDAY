# Firmware Audit: TP-Link Archer A9 / Archer_A9_US__V6_210315.zip

- Source URL: https://static.tp-link.com/firmware/2021/202106/20210610/Archer A9(US)_V6_210315.zip
- Local path: known_firmware/firmware/TP-Link_Archer_A9/Archer_A9_US__V6_210315.zip
- SHA-256: `9b46e5c1080a36d4280842a71ba6af7205a06ec540c135d072427bcfc0a5efd1`
- Size: 16291681 bytes
- Version: unknown
- Release date: 2021-06-10

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `SshD`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, Boa, bOa, boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/9b46e5c1080a36d4 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/9b46e5c1080a36d4/_Archer_A9_US__V6_210315.zip.extracted/_a9v6_us_ru-up-ver1-1-1-P1[20210315-rel40637]_2021-03-15_11.20.13.bin.extracted/squashfs-root/etc/ppp/resolv.conf -> /tmp/resolv.conf.ppp; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
