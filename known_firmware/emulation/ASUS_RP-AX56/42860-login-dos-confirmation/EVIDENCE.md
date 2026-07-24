# RP-AX56 3.0.0.4.386_42860 unauthenticated HTTP DoS confirmation

- Firmware archive SHA-256:
  `eb39365e9847ca830a67f626e1295785dd87837d4c3e0a031452b0bcad8a5e4c`
- Exact `httpd` SHA-256:
  `0194c6115b18af9443992ccae6d3fe3b0df0d294c335151744ce16c15e7fac43`
- Target: exact ARM firmware `httpd` under Greenhouse user-mode emulation
- Network: Docker `--network none`; request sent only to guest loopback
- Authentication: no Cookie or Authorization header

The service returned HTTP 200 before the probe. This request was then sent:

```http
GET /login.cgi HTTP/1.1
Host: 127.0.0.1
User-Agent: asusrouter-Windows-DUTUtil-1.0.1.278
Connection: close
```

The request returned zero bytes. The emulator recorded:

```text
[GreenHouseQEMU] SIGSEGV CAUGHT!
[GreenHouseQEMU] SIG 11
Segmentation fault (core dumped)
```

The `httpd` process stopped responding; a subsequent loopback request failed
with a connection reset. This confirms an unauthenticated service DoS in this
RP-AX56 build, consistent with CVE-2023-34359.

The CVE-2023-34358 one-byte body regression request returned HTTP 200 and did
not crash this setup-state profile.

## Latest-version control

The exact `httpd` from RP-AX56 3.0.0.4.386_51891 (SHA-256
`aa5f8d3a2a64e9ff3ea9ed997fc774f215077669336d3142bc39ff361b52a504`)
was run with the same component root, Greenhouse runtime, NVRAM profile, and
loopback requests:

- CVE-2023-34359 request: process PID unchanged; HTTP remained 200.
- CVE-2023-34358 request: process PID unchanged; HTTP remained 200.

This component-level differential validates that the 51891 `httpd` no longer
exhibits the confirmed login crash under the tested conditions.

## Preserved evidence

- `GREENHOUSE_STDLOG`: emulator bind and SIGSEGV output
- `trace.log`: syscall trace for the exact firmware process
- `response.bin`: empty crash-request response

SHA-256 values at collection:

```text
150fe305011589187bd2a86518a82f356d7aa6dbc59493c346e6b1debe32750f  GREENHOUSE_STDLOG
a6e18cfe14b20c296063b49c018159ad5e8f561106406ad2337b73db1d14d69a  trace.log
e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855  response.bin
```
