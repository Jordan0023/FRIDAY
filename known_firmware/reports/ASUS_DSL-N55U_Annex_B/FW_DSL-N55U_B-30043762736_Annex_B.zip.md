# Firmware Audit: ASUS DSL-N55U Annex B / FW_DSL-N55U_B-30043762736_Annex_B.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/DSL-N55U_B1/FW_DSL-N55U_B-30043762736_Annex_B.zip
- Local path: known_firmware/firmware/ASUS_DSL-N55U_Annex_B/FW_DSL-N55U_B-30043762736_Annex_B.zip
- SHA-256: `abeab916e6524ddf2602b104deb7f435d0237030f36ee1932fa90a9c24ef066a`
- Size: 8324077 bytes
- Version: 3.0.0.4.376_2736
- Release date: 2015/01/19

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `Boa`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/abeab916e6524ddf exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
