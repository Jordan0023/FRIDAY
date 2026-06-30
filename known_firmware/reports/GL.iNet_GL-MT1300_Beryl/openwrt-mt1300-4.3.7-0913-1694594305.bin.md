# Firmware Audit: GL.iNet GL-MT1300 Beryl / openwrt-mt1300-4.3.7-0913-1694594305.bin

- Source URL: https://fw.gl-inet.com/firmware/mt1300/release4/openwrt-mt1300-4.3.7-0913-1694594305.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT1300_Beryl/openwrt-mt1300-4.3.7-0913-1694594305.bin
- SHA-256: `64009e6e05b703cae582157d218a35d5c4e5a77e03ac51d361d78bbd707fe77c`
- Size: 17304136 bytes
- Version: 4.3.7
- Release date: 2023-09-13 16:36:50

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/64009e6e05b703ca exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/64009e6e05b703ca/_openwrt-mt1300-4.3.7-0913-1694594305.bin.extracted/squashfs-root-0/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
