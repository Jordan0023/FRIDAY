# Firmware Audit: MR814V1 / MR814v1_Firmware_Version_4.14_Release_Candidate_4.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/MR814v1/MR814v1%20Firmware%20Version%204.14%20Release%20Candidate%204.zip
- Local path: known_firmware/firmware/MR814V1/MR814v1_Firmware_Version_4.14_Release_Candidate_4.zip
- SHA-256: `e9e97b72c8cd3c762c3501ce557fbe2708583c5b06778e367d340efb4bb17d38`
- Size: 695066 bytes
- Version: unknown
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `password`

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `cgi-bin, httpd`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `Eval, SYSTEM, System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/e9e97b72c8cd3c76 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
