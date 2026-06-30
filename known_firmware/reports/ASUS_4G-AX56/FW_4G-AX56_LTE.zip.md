# Firmware Audit: ASUS 4G-AX56 / FW_4G-AX56_LTE.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/4G-AX56/FW_4G-AX56_LTE.zip
- Local path: known_firmware/firmware/ASUS_4G-AX56/FW_4G-AX56_LTE.zip
- SHA-256: `b209d8acde7366cdca71eaa68166eef38d7701323792e2765691ea5c450aa21a`
- Size: 34832592 bytes
- Version: 4G-AX56_LTE firmware
- Release date: 2022/01/14

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa, bOa, boa`

### Setuid files present

Setuid binaries can become privilege-escalation paths if they process attacker-controlled input.

Evidence: `known_firmware/extracted/b209d8acde7366cd/_FW_4G-AX56_LTE.zip.extracted/_lte_fw.tgz.extracted/_0.extracted/_16121.1000.00.01.01.39.pac.extracted/_17B0698.extracted/cpio-root/sbin/reboot.sysvinit, known_firmware/extracted/b209d8acde7366cd/_FW_4G-AX56_LTE.zip.extracted/_lte_fw.tgz.extracted/_0.extracted/_16121.1000.00.01.01.39.pac.extracted/_17B0698.extracted/cpio-root/sbin/halt.sysvinit, known_firmware/extracted/b209d8acde7366cd/_FW_4G-AX56_LTE.zip.extracted/_lte_fw.tgz.extracted/_0.extracted/_16121.1000.00.01.01.39.pac.extracted/_17B0698.extracted/cpio-root/sbin/poweroff.sysvinit, known_firmware/extracted/b209d8acde7366cd/_FW_4G-AX56_LTE.zip.extracted/_lte_fw.tgz.extracted/_0.extracted/_16121.1000.00.01.01.39.pac.extracted/_17B0698.extracted/cpio-root/sbin/shutdown.sysvinit, known_firmware/extracted/b209d8acde7366cd/_FW_4G-AX56_LTE.zip.extracted/_lte_fw.tgz.extracted/_0.extracted/_16121.1000.00.01.01.39.pac.extracted/_17B0698.extracted/cpio-root/bin/busybox.suid`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/b209d8acde7366cd exited 0: WARNING: Symlink points outside of the extraction directory: /workspaces/FRIDAY/known_firmware/extracted/b209d8acde7366cd/_FW_4G-AX56_LTE.zip.extracted/_lte_fw.tgz.extracted/_0.extracted/_16121.1000.00.01.01.39.pac.extracted/_17B0698.extracted/cpio-root/bin/usleep -> /usr/bin/busybox.nosuid; changing link target to /dev/null for security purposes.

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
