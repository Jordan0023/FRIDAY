# Conditional no-credentials IFTTT-to-config-sync overflow chain

## Result

The exact RT-AX82U firmware `3.0.0.4.388_25101` reproduced the complete chain
without supplying administrator credentials or a preexisting administrator
token:

1. The isolated guest modeled retained post-reboot IFTTT state with short token
   `0` and a stored generation uptime greater than current uptime.
2. An unauthenticated request to `get_IFTTTtoken.cgi` returned
   `error_status="0"` and a 31-byte `ifttt_token`.
3. The recovered value was used as the `asus_token` cookie for
   `POST /upload_config_sync.cgi`.
4. The protected route staged and parsed the inert oversized `HDR1` profile.
5. The saved program counter was replaced with `0x41414141` and the exact
   firmware process received `SIGSEGV`.
6. The isolated emulator exited with status 139.

The recovered token was never printed or copied into the evidence directory.
The response file containing it remained only in the stopped isolated guest.

## Trace evidence

The trace segment records the full security-boundary transition:

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

This proves that the recovered IFTTT value passed the protected route's token
check and reached the vulnerable callback before the controlled fault.

## Scope and classification

This is a confirmed **conditional no-admin-credentials chain**, not an
unconditional tokenless exploit. Real-world exploitation requires all of the
following:

- IFTTT/Alexa was configured previously so retained short-token state exists;
- the router rebooted while the stored generation uptime exceeds its new
  uptime;
- the attacker guesses the short token before the current firmware's
  three-mismatch clearing limit; and
- the management service is network-reachable by the attacker.

The IFTTT authentication component is public prior art
(CVE-2022-35401/TALOS-2022-1586). The newly confirmed component is the
configuration-sync stack overflow with program-counter control. Combining them
demonstrates that the new overflow can be triggered without the victim giving
the attacker an administrator token, but it does not make the historical
authentication weakness novel.

## Preserved files

- `overflow.prf` — inert `HDR1` crash profile, SHA-256
  `eb4215e7c5df566898df4b64a6dce1352aff7b45f0aebbf70079b412a8abecca`
- `trace.e2e.log` — exact-firmware syscall trace, SHA-256
  `523924c15c0502509840ae0c0e85debe467070fbbfbe82be48c2516badd96517`
- `trace-offset.txt` — byte offset marking the chain run, SHA-256
  `140c04d78a691c642140248d898ca7f03173448feabb3e21f9b106249509e509`
