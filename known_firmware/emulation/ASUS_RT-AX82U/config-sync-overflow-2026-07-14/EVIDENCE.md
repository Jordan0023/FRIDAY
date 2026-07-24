# RT-AX82U configuration-sync stack overflow

## Result

The exact RT-AX82U firmware `3.0.0.4.388_25101` contains an authenticated
stack-buffer overflow in `upload_config_sync_cgi`. A bounded inert profile
overwrote the saved return address with `0x41414141`; the exact firmware HTTP
process received `SIGSEGV` at that address and the emulation container exited
with status 139.

This is an L5 reproducible authenticated memory-corruption vulnerability with
program-counter control. No code-execution payload was developed or needed.

## Target

- Model: ASUS RT-AX82U
- Firmware: `3.0.0.4.388_25101`
- Firmware SHA-256: `00e344c92be2eceb43e3bbd3820c652b11c99f572adfe4bf5cb18c16df2aa916`
- Vulnerable library: `usr/lib/libwebapi.so`
- Library SHA-256: `3e2a792c32f2905b4ac5c65fc2ac5f16673c7ab93a64378078c0bc2bdf3e73c0`
- Route: `POST /upload_config_sync.cgi`
- Handler: `upload_config_sync_cgi` at `0x77a0`

Testing occurred only in the internal exact-firmware QEMU/Docker guest. The
request used the existing synthetic firmware-issued lab token.

## Root cause

The function reserves `0x40000` bytes for its profile body plus 32 bytes of
locals:

```text
0x77a4  sub sp, sp, #0x40000
0x77a8  sub sp, sp, #0x20
0x77b0  add r5, sp, #0x20       ; body buffer
```

For an `HDR1` profile it loads the attacker-controlled 32-bit body length from
the eight-byte header and passes it directly to `fread`:

```text
0x7880  ldr r2, [r5, #-4]       ; declared body length
0x788c  mov r0, r5              ; 0x40000-byte stack buffer
0x7890  bl  fread
```

There is no comparison between the declared length and `0x40000`, and this
library has no stack-canary check in the function. The saved registers begin
immediately above the body buffer.

## Dynamic confirmation

Controls:

- An unauthenticated valid small profile was rejected and produced no sync
  artifact; HTTP remained healthy.
- An authenticated valid small profile reached the callback and created
  `/tmp/save_config_sync.json`; HTTP remained healthy.
- Setting the synthetic guest to factory/QIS state (`x_Setting=0`) did not make
  this route unauthenticated. The valid small profile was still rejected.

The controlled fault profile contained:

- magic `HDR1`;
- little-endian declared body length `0x40020`;
- an inert body beginning with NUL and filled with `A` bytes.

The trace records the full attacker-controlled read and subsequent return-address
fault:

```text
read(5,0x407bf100,258048) = 258048
read(5,0x131338,4096) = 32
...
--- SIGSEGV {si_signo=SIGSEGV, si_code=1, si_addr=0x41414141} ---
```

After consuming the header from stdio's initial 4096-byte buffer, `fread` copies
the remaining buffered bytes and reads another `0x3f000` bytes. Its final
32-byte read crosses the `0x40000` body-buffer boundary and replaces the saved
frame with `A` bytes.

## Version evidence

RT-AX82U `3.0.0.4.388_25098` contains the byte-identical vulnerable
`libwebapi.so`, establishing at least two affected releases.

Newer ASUS 3.0.0.6 firmware examined from ZenWiFi BD4/BD5/BE5000 contains a
changed version of this function. It explicitly compares the declared length
with `0x40000` before `fread` and also checks a stack canary:

```text
cmp r2, #0x40000
bls bounded_fread
...
bl __stack_chk_fail
```

This is strong patch-differential evidence for the defect, but does not by
itself establish which models or releases ASUS considers affected.

## Novelty and classification

Public searches performed on 2026-07-14 for the exact route, handler,
`settings_u.prf`, `HDR1`, and ASUS configuration-sync stack overflow found no
matching advisory or technical disclosure. Results included unrelated older
ASUS URL-processing overflows and general configuration-backup documentation.

Classification: **confirmed authenticated stack-buffer overflow with PC
control; zero-day candidate pending ASUS/CNA adjudication**. It is not an
unconditional pre-authentication vulnerability. The separately reproduced
CVE-2022-35401 IFTTT token-recovery condition can supply an administrator token
without normal credentials in a narrow retained-state window, but that
authentication component is public prior art and conditional.

## Preserved evidence

- `hdr1-frame.prf` — SHA-256
  `eb4215e7c5df566898df4b64a6dce1352aff7b45f0aebbf70079b412a8abecca`
- `trace.e2e.log` — SHA-256
  `e99a0a671beafaca6b21d8e51bf55233c241336e67d4a9019fb0e8589c6ddf9f`
- `GREENHOUSE_STDLOG.e2e` — SHA-256
  `ce9f905f22829d01fad7018cb05f1c8d651b9d01ca3d0f81998877d4eb3aeb56`

Recommended remediation is to reject every declared body length greater than
the destination buffer before reading, require the file to contain the entire
declared body, enforce termination within the received length, and compile the
handler with stack protection. The 3.0.0.6 implementation supplies a concrete
reference for the missing maximum-length check.
