# Firmware Audit: WNHDE111 / WNHDE111_Firmware_Version_1.2.7_1.0.1__North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNHDE111/WNHDE111%20Firmware%20Version%201.2.7_1.0.1%20(North%20America).zip
- Local path: known_firmware/firmware/WNHDE111/WNHDE111_Firmware_Version_1.2.7_1.0.1__North_America_.zip
- SHA-256: `a6aff59922bd8e3348ca89ebaadcb59b05d4171a1ef88e543ffbe6ad2dae9409`
- Size: 1488278 bytes
- Version: 2.7_1.0.1__North_America_
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/a6aff59922bd8e33 exited 0: WARNING: Extractor.execute failed to run external extractor 'arj -y e '%e'': [Errno 2] No such file or directory: 'arj', 'arj -y e '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
