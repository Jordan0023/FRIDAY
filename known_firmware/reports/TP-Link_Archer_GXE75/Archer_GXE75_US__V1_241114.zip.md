# Firmware Audit: TP-Link Archer GXE75 / Archer_GXE75_US__V1_241114.zip

- Source URL: https://static.tp-link.com/upload/firmware/2024/202412/20241205/Archer GXE75(US)_V1_241114.zip
- Local path: known_firmware/firmware/TP-Link_Archer_GXE75/Archer_GXE75_US__V1_241114.zip
- SHA-256: `dd1869ad93703f0f238c00403522cbe59b166359196d2457cd67ed5542ce480f`
- Size: 61415781 bytes
- Version: V1.6_1.0.4 Build 20241114
- Release date: 2024-12-05

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/dd1869ad93703f0f exited 0: WARNING: Extractor.execute failed to run external extractor 'unstuff '%e'': [Errno 2] No such file or directory: 'unstuff', 'unstuff '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
