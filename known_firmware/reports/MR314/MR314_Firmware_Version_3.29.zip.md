# Firmware Audit: MR314 / MR314_Firmware_Version_3.29.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/MR314/MR314%20Firmware%20Version%203.29.zip
- Local path: known_firmware/firmware/MR314/MR314_Firmware_Version_3.29.zip
- SHA-256: `db0a49c1e5a01507c874b66b2743ed3c4f6f32a881df154bf58e3828689d9cd5`
- Size: 923034 bytes
- Version: unknown
- Release date: unknown

## Static Findings

### Hard-coded credentials or secrets

Hard-coded secrets should be reviewed for default credentials, service tokens, or recoverable admin passwords.

Evidence: `Password`

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/db0a49c1e5a01507 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
