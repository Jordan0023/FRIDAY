# Firmware Audit: GL.iNet GL-MT1300 Beryl / openwrt-mt1300-4.3.10-0202-1706857916.bin

- Source URL: https://fw.gl-inet.com/firmware/mt1300/release4/openwrt-mt1300-4.3.10-0202-1706857916.bin
- Local path: known_firmware/firmware/GL.iNet_GL-MT1300_Beryl/openwrt-mt1300-4.3.10-0202-1706857916.bin
- SHA-256: `19a767337ea2483351c1c4d8f1ed6dbffac12026b96af418f4237ba159d53312`
- Size: 17304316 bytes
- Version: 4.3.10
- Release date: 2024-02-02 15:09:55

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, boA, boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/19a767337ea24833 exited 0: WARNING: Symlink points outside of the extraction directory: /home/jordan/FRIDAY/known_firmware/extracted/19a767337ea24833/_openwrt-mt1300-4.3.10-0202-1706857916.bin.extracted/squashfs-root/usr/bin/ssh -> /usr/sbin/dropbear; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
