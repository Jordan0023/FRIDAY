# Firmware Audit: RAX45 / RAX45-V1.0.2.28_2.0.36.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX45/RAX45-V1.0.2.28_2.0.36.zip
- Local path: known_firmware/firmware/RAX45/RAX45-V1.0.2.28_2.0.36.zip
- SHA-256: `86918eb692905d1a203a344fcdb74a865bc7ef06c4956eeb89a676cccc2752d4`
- Size: 65565419 bytes
- Version: 1.0.2.28_2.0.36
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `system`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/86918eb692905d1a exited 0: WARNING: Extractor.execute failed to run external extractor 'ubireader_extract_files -o 'ubifs-root' '%e'': [Errno 2] No such file or directory: 'ubireader_extract_files', 'ubireader_extract_files -o 'ubifs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
