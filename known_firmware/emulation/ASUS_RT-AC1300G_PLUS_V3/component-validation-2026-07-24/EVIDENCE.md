# Component validation evidence

Firmware archive SHA-256:
`2173b5a63e83720b556e6fe1956446e8559b16efd9ea927cb3ff98894461f6c1`

## HTTP

- Stock binary: `/usr/sbin/httpd`
- Binary SHA-256:
  `e04b631a12452c915a91c9c330d9258464c62f8e337205ca23cc868b5aa92297`
- Runtime: big-endian MIPS user-mode QEMU, stock root filesystem, loopback
  port 28081, factory-setup NVRAM scaffold
- `/` control: HTTP 200, setup redirect
- CVE-2023-34358 regression: process remained live
- CVE-2023-34359 regression: HTTP live before, dead after, target SIGSEGV

## infosvr

- Stock binary: `/usr/sbin/infosvr`
- Binary SHA-256:
  `fa372130eac00ae5cc4d3ecbb1a71c6db47e2d76f2a94667d1c15a5772d6f07b`
- Runtime: same component root, UDP/9999
- Opcode-31 control: 512-byte response before and after corpus
- Historical opcode-51 marker: absent
- Process after bounded corpus: live
- Implemented response opcodes observed: 31, 52, 53, 54

The NVRAM compatibility source used for startup is
`scripts/shims/asus_mips_nvram_shim.c`. It does not patch either stock daemon.
