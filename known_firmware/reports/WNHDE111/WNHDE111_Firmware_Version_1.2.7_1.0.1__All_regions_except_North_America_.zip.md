# Firmware Audit: WNHDE111 / WNHDE111_Firmware_Version_1.2.7_1.0.1__All_regions_except_North_America_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNHDE111/WNHDE111%20Firmware%20Version%201.2.7_1.0.1%20(All%20regions%20except%20North%20America).zip
- Local path: known_firmware/firmware/WNHDE111/WNHDE111_Firmware_Version_1.2.7_1.0.1__All_regions_except_North_America_.zip
- SHA-256: `d4ef6b3a67e6e5f8935f0537591561bf8ca03b050edf63a17d9e9299d6404b77`
- Size: 1498788 bytes
- Version: 2.7_1.0.1__All_regions_except_North_America_
- Release date: unknown

## Static Findings

No heuristic findings were identified. This does not prove the firmware is vulnerability-free.
## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/d4ef6b3a67e6e5f8 exited 0: WARNING: Extractor.execute failed to run external extractor 'arj -y e '%e'': [Errno 2] No such file or directory: 'arj', 'arj -y e '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
