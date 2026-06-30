# Firmware Audit: TP-Link Archer AXE300 / Archer_AXE300_US__V1_220907.zip

- Source URL: https://static.tp-link.com/upload/firmware/2022/202209/20220922/Archer AXE300(US)_V1_220907.zip
- Local path: known_firmware/firmware/TP-Link_Archer_AXE300/Archer_AXE300_US__V1_220907.zip
- SHA-256: `68075aa9bd99c207576a6f078aa52fb0379cceddf29e328f3b95e4c57b691270`
- Size: 46121851 bytes
- Version: V1.6_1.0.3 Build 20220907
- Release date: 2022-09-22

## Static Findings

### HTTP CGI/admin attack surface

Web admin components should be reviewed for authentication bypass, command injection, and unsafe parameter parsing.

Evidence: `BOa, BoA`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/68075aa9bd99c207 exited 0

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
