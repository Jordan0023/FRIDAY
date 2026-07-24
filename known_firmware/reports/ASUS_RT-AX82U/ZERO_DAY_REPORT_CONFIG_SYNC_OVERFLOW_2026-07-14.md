# ASUS RT-AX82U configuration-import stack overflow

## Summary

An authenticated stack-buffer overflow exists in the configuration
synchronization importer of the ASUS RT-AX82U. A crafted `HDR1` configuration
profile supplied to:

```text
POST /upload_config_sync.cgi
```

causes the firmware to copy an attacker-controlled amount of data into a fixed
`0x40000`-byte stack buffer. The uploaded length is not validated before being
passed to `fread`.

The handler requires an administrator-equivalent token, but the attacker does
not necessarily need administrator credentials or a previously supplied token.
The confirmed conditional chain recovers the required token through retained
IFTTT state (CVE-2022-35401) and then triggers the overflow. No unconditional
request that omits a token at the handler has been demonstrated.

Dynamic testing against the exact firmware demonstrated control of the saved
program counter. The firmware HTTP process terminated with:

```text
SIGSEGV: si_addr=0x41414141
```

Based on the technical confirmation and absence of a matching public
disclosure, this is classified as an apparent zero-day. Private or embargoed
prior knowledge cannot be independently excluded.

## Affected product

| Field | Value |
|---|---|
| Vendor | ASUS |
| Product | RT-AX82U |
| Confirmed firmware | `3.0.0.4.388_25101` |
| Also affected | `3.0.0.4.388_25098` |
| Component | `usr/lib/libwebapi.so` |
| Handler | `upload_config_sync_cgi` |
| Route | `POST /upload_config_sync.cgi` |
| Handler authorization | An administrator-equivalent `asus_token` must be presented to the vulnerable route |
| Attacker prerequisites | Either possess such a token, or conditionally recover one through CVE-2022-35401 retained IFTTT state |
| Password required for confirmed chain | No; the conditional chain recovered the token without administrator credentials |

Firmware SHA-256:

```text
00e344c92be2eceb43e3bbd3820c652b11c99f572adfe4bf5cb18c16df2aa916
```

Vulnerable library SHA-256:

```text
3e2a792c32f2905b4ac5c65fc2ac5f16673c7ab93a64378078c0bc2bdf3e73c0
```

## Security impact

A successful attacker can corrupt the stack and control the saved program
counter of the privileged firmware HTTP process. Confirmed impact includes:

- remote termination of the management service;
- attacker-controlled program counter; and
- potential arbitrary code execution, subject to the target's exploit
  mitigations and runtime environment.

No command-execution or persistence payload was developed. Program-counter
control establishes memory corruption and potential code-execution impact.

## Authorization boundary and credential requirements

The vulnerable route itself checks for a valid administrator-equivalent
`asus_token`. This does **not** mean the attacker must be given that token or
know the administrator password. In the confirmed conditional chain, the
firmware generated and returned the required token through the retained-state
IFTTT weakness, after which the attacker-controlled request presented it to the
vulnerable route.

Accordingly:

- direct exploitation requires possession of an administrator-equivalent token;
- the confirmed conditional chain does not require supplied administrator
  credentials or a preexisting attacker-held token; and
- no unconditional path that reaches the handler without presenting any token
  has been demonstrated.

Testing confirmed:

- an unauthenticated request was rejected;
- factory/QIS state did not remove authentication;
- WAN Remote Administration is not required when the attacker can access the
  LAN management interface; and
- WAN exposure depends on the router's management configuration.

The historical CVE-2022-35401 IFTTT weakness conditionally provides the
administrator-equivalent token without the password, but requires prior
smart-home configuration and retained reboot state. That authentication
weakness is public prior art and is not the new root cause.

The complete conditional chain was reproduced in the exact-firmware guest. An
unauthenticated IFTTT recovery request generated a 31-byte token without supplied
administrator credentials; the protected configuration-sync route accepted that
value and the inert overflow profile produced `SIGSEGV` at `0x41414141`. This
confirms a conditional no-admin-credentials path while preserving the distinction
from an unconditional tokenless exploit.

## Conditional no-admin-credentials chain

The end-to-end chain was reproduced without supplying administrator credentials
or a preexisting administrator token:

1. The isolated guest modeled retained post-reboot IFTTT state with short token
   `0` and a stored generation uptime greater than current uptime.
2. An unauthenticated request to `get_IFTTTtoken.cgi` used the expected IFTTT
   User-Agent and supplied `shortToken=0`.
3. The firmware returned `error_status="0"` and a 31-byte `ifttt_token`.
4. The recovered value was supplied as the `asus_token` cookie to
   `POST /upload_config_sync.cgi`.
5. The protected route staged `/tmp/settings_u.prf` and entered
   `upload_config_sync_cgi`.
6. The inert oversized `HDR1` body replaced the saved program counter with
   `0x41414141`.
7. The exact firmware process received `SIGSEGV`; the isolated emulator exited
   with status 139.

The recovered token was not printed or copied into the report evidence. The
trace independently records the security-boundary transition:

```text
openat(...,"/gh_nvram/ifttt_timestamp",O_RDONLY)
openat(...,"/gh_nvram/ifttt_stoken",O_RDONLY)
openat(...,"/gh_nvram/ifttt_token",O_RDWR|O_CREAT|O_TRUNC,0666)
...
openat(...,"/gh_nvram/ifttt_token",O_RDONLY)
openat(...,"/tmp/settings_u.prf",O_WRONLY|O_CREAT|O_TRUNC,0666)
openat(...,"/tmp/settings_u.prf",O_RDWR)
openat(...,"/tmp/save_config_sync.json",O_WRONLY|O_CREAT|O_TRUNC,0644)
...
--- SIGSEGV {si_signo=SIGSEGV, si_code=1, si_addr=0x41414141} ---
```

This chain is conditional rather than universally tokenless. It requires:

- previous IFTTT or Alexa configuration;
- retained short-token state across a router reboot;
- current uptime lower than the stored token-generation uptime;
- a correct short-token guess before the firmware clears state after three
  mismatches; and
- network reachability to the management service.

The authentication component is CVE-2022-35401/TALOS-2022-1586 and therefore
public prior art. Its inclusion does not make that component novel. The new
finding is the configuration-sync stack overflow; the chain demonstrates that
the new memory-corruption primitive can be reached without the victim handing
the attacker an administrator token when the historical prerequisites hold.

## Root cause

The vulnerable function reserves a `0x40000`-byte stack buffer:

```text
0x77a4  sub sp, sp, #0x40000
0x77a8  sub sp, sp, #0x20
0x77b0  add r5, sp, #0x20
```

For an `HDR1` profile, it loads the attacker-controlled body length and passes
it directly to `fread`:

```text
0x7880  ldr r2, [r5, #-4]
0x788c  mov r0, r5
0x7890  bl  fread
```

There is no comparison between the declared length and the destination
capacity. The function also lacks a stack-canary check. A body longer than
`0x40000` bytes therefore overwrites saved stack-frame values, including the
return address.

## Reproduction result

A bounded inert profile used:

```text
Magic:        HDR1
Body length:  0x40020, little-endian
Body:         NUL followed by A bytes
```

The trace recorded the oversized read followed by the attacker-controlled
program-counter failure:

```text
read(5,0x407bf100,258048) = 258048
read(5,0x131338,4096) = 32
...
--- SIGSEGV {si_signo=SIGSEGV, si_code=1, si_addr=0x41414141} ---
```

The exact-firmware emulator exited with status 139.

The controlled verifier is located at:

```text
known_firmware/reports/ASUS_RT-AX82U/pocs/rt_ax82u_config_sync_overflow_verify.py
```

It is restricted to loopback and contains no code-execution payload.

## Control tests

- A valid small profile without authentication was rejected.
- The HTTP service remained healthy after the unauthenticated control.
- A valid small authenticated profile reached the importer and generated
  `/tmp/save_config_sync.json`.
- The oversized authenticated profile produced the controlled `0x41414141`
  fault.
- Setting `x_Setting=0` did not make the route unauthenticated.

## Version and patch comparison

RT-AX82U firmware `388_25098` contains the byte-identical vulnerable
`libwebapi.so`, confirming at least two affected releases.

A newer implementation examined in ASUS 3.0.0.6 firmware explicitly validates
the declared size:

```text
cmp r2, #0x40000
bls bounded_fread
```

It also includes stack-canary enforcement through `__stack_chk_fail`. This is
strong differential evidence for the missing validation in the affected
implementation.

## Zero-day classification

Public searches conducted on July 14, 2026 found no advisory or technical
disclosure matching:

- `upload_config_sync.cgi`;
- `upload_config_sync_cgi`;
- `settings_u.prf`;
- the ASUS `HDR1` configuration-sync overflow; or
- this specific unchecked-length root cause.

Classification:

> Technically confirmed authenticated stack-buffer overflow with
> program-counter control; apparent zero-day based on available public
> information.

Additional chain classification:

> Confirmed conditional no-admin-credentials chain using public
> CVE-2022-35401 token recovery followed by the apparent zero-day
> configuration-sync stack overflow. Not an unconditional pre-authentication
> vulnerability.

## Recommended remediation

ASUS should:

- reject declared lengths exceeding the destination capacity before `fread`;
- verify that the uploaded file contains the complete declared body;
- terminate and parse strings only within the received length;
- enable stack-canary protection for the handler;
- audit the `HDR2`, `BLUE`, and related configuration formats;
- audit sibling backup and restore handlers for the same trusted-length
  pattern; and
- backport the corrected 3.0.0.6 validation to supported RT-AX82U firmware.

## Preserved evidence

Full evidence and hashes are stored in:

```text
known_firmware/emulation/ASUS_RT-AX82U/config-sync-overflow-2026-07-14/
```

The directory contains the technical evidence record, exact QEMU syscall trace,
emulator log, and inert crash profile.

Conditional-chain evidence is stored in:

```text
known_firmware/emulation/ASUS_RT-AX82U/ifttt-config-sync-chain-2026-07-14/
```

Preserved chain artifacts:

- `overflow.prf` — SHA-256
  `eb4215e7c5df566898df4b64a6dce1352aff7b45f0aebbf70079b412a8abecca`;
- `trace.e2e.log` — SHA-256
  `523924c15c0502509840ae0c0e85debe467070fbbfbe82be48c2516badd96517`;
  and
- `trace-offset.txt` — SHA-256
  `140c04d78a691c642140248d898ca7f03173448feabb3e21f9b106249509e509`.
