# Firmware Audit: WNR2000V1 / WNR2000_Firmware_Version_1.2.3.7__NA_.zip

- Source URL: https://www.downloads.netgear.com/files/GDC/WNR2000V1/WNR2000%20Firmware%20Version%201.2.3.7%20(NA).zip
- Local path: known_firmware/firmware/WNR2000V1/WNR2000_Firmware_Version_1.2.3.7__NA_.zip
- SHA-256: `90bf2ee87b9fd42fb28a787e1516cb7cbbb604ead6c17ca00f869b0d0fb1c34f`
- Size: 2690855 bytes
- Version: 2.3.7__NA_
- Release date: unknown

## Static Findings

### Command execution helpers

Command execution paths are common command-injection sinks when reachable from web or network inputs.

Evidence: `System, system`

### Potential memory-unsafe C functions

Unsafe C library calls can indicate buffer overflow risk; confirm whether inputs are bounded before use.

Evidence: `gets, sprintf, strcat`

## Extraction Notes

- binwalk -eM --directory known_firmware/extracted/90bf2ee87b9fd42f exited 0: WARNING: Extractor.execute failed to run external extractor 'sasquatch -p 1 -be -d 'squashfs-root' '%e'': [Errno 2] No such file or directory: 'sasquatch', 'sasquatch -p 1 -be -d 'squashfs-root' '%e'' might not be installed correctly

## Decompiler Notes

- Ghidra analyzeHeadless not found; decompiler import skipped.

## Validation Needed

These are static-analysis leads. Confirm reachability, affected versions, exploit preconditions, and vendor-fixed versions before treating any item as a vulnerability.
