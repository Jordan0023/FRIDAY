# Firmware Audit: TP-Link AD7200 / AD7200_EU_US__V2.0_210430.zip

- Source URL: https://static.tp-link.com/upload/firmware/2022/202207/20220720/AD7200(EU_US)_V2.0_210430.zip
- Local path: known_firmware/firmware/TP-Link_AD7200/AD7200_EU_US__V2.0_210430.zip
- SHA-256: `60f753419137504b369ad74ffe8b825dd0a397cbab13c5fe43ced276c2b866ec`
- Size: 20596994 bytes
- Version: V2_2.0.2 Build 20210430
- Release date: 2022-07-20

## Static Findings

### Remote shell services present

Remote shell daemons increase attack surface and should be verified as disabled by default and authenticated safely.

Evidence: `dropbear`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BoA, bOa, boa, cgi-bin, httpd, uhttpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/60f753419137504b exited 0: WARNING: Extractor.execute failed to run external extractor 'lha efi '%e'': [Errno 2] No such file or directory: 'lha', 'lha efi '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
