# Firmware Audit: TP-Link Archer C90 / Archer_C90_US__V6_210315.zip

- Source URL: https://static.tp-link.com/upload/firmware/2022/202201/20220110/Archer C90(US)_V6_210315.zip
- Local path: known_firmware/firmware/TP-Link_Archer_C90/Archer_C90_US__V6_210315.zip
- SHA-256: `61dc325d379b0de0299d90755758c5018c1f6c326f7a471405e9b2c7b80789b8`
- Size: 16291995 bytes
- Version: unknown
- Release date: 2022-01-10

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

- binwalk -eM --directory known_firmware/extracted/61dc325d379b0de0 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/61dc325d379b0de0/_Archer_C90_US__V6_210315.zip.extracted/Archer C90(US)_V6_210315/_c90v6_us_ru-up-ver1-1-1-P1[20210315-rel40637]_2021-03-15_11.20.13.bin.extracted/squashfs-root/etc/ppp/resolv.conf -> /tmp/resolv.conf.ppp; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
