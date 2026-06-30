# Firmware Audit: RAX78 / RAX78-V1.0.19.172.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/RAX78/RAX78-V1.0.19.172.zip
- Local path: known_firmware/firmware/RAX78/RAX78-V1.0.19.172.zip
- SHA-256: `af00710372b788e0cdd2ab0735a1bf0e53a242497b8ca05a7dba8456df1d63e4`
- Size: 67756891 bytes
- Version: 1.0.19.172
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/af00710372b788e0 exited 0: WARNING: Extractor.execute failed to run external extractor 'jefferson -d 'jffs2-root' '%e'': [Errno 2] No such file or directory: 'jefferson', 'jefferson -d 'jffs2-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
