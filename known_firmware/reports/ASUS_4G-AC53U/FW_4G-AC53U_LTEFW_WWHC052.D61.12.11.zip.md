# Firmware Audit: ASUS 4G-AC53U / FW_4G-AC53U_LTEFW_WWHC052.D61.12.11.zip

- Source URL: https://dlcdnta.asus.com/pub/ASUS/wireless/4G-AC53U/FW_4G-AC53U_LTEFW_WWHC052.D61.12.11.zip
- Local path: known_firmware/firmware/ASUS_4G-AC53U/FW_4G-AC53U_LTEFW_WWHC052.D61.12.11.zip
- SHA-256: `3784d73d850c90ff6dd32bdc657bb11e4f39b60398905178b20fc32e1d8f4992`
- Size: 61995990 bytes
- Version: WWHC052.D61.12.11.102.B
- Release date: 2018/06/12

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOA, BOa, Boa, bOA, bOa, boa, cgi-bin, lighttpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `SYSTEM, System, eval, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `sprintf`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/3784d73d850c90ff exited 0: WARNING: Extractor.execute failed to run external extractor 'yaffshiv --auto --brute-force -f '%e' -d 'yaffs-root'': [Errno 2] No such file or directory: 'yaffshiv', 'yaffshiv --auto --brute-force -f '%e' -d 'yaffs-root'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
