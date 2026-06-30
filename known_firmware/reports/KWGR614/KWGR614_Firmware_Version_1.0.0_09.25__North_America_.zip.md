# Firmware Audit: KWGR614 / KWGR614_Firmware_Version_1.0.0_09.25__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/KWGR614/KWGR614%20Firmware%20Version%201.0.0_09.25%20(North%20America).zip
- Local path: known_firmware/firmware/KWGR614/KWGR614_Firmware_Version_1.0.0_09.25__North_America_.zip
- SHA-256: `0d8a9786ea0c641502c8007946a519338215a8ef6acc4fbc8fa5e975d46f390d`
- Size: 1816906 bytes
- Version: 0.0_09.25__North_America_
- Release date: unknown

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `boA`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/0d8a9786ea0c6415 exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
