# Conditional pre-authentication chain — ASUS RT-AX82U

## Decision

The server-certificate TAR vulnerability directly requires an administrator
session. A **conditional pre-authentication chain** was nevertheless reproduced
against firmware `3.0.0.4.388_25101` by combining it with the residual IFTTT
short-token behavior in `get_IFTTTtoken.cgi`.

This is not an unconditional authentication bypass. It requires:

1. IFTTT/Alexa integration to have been configured previously, leaving
   `ifttt_stoken` and `ifttt_timestamp` in NVRAM;
2. a subsequent router reboot, making current uptime lower than the stored
   generation uptime; and
3. a correct guess within the current firmware's three-attempt limit.

The short token has 255 possible values. The current firmware clears the stored
token and timestamp after repeated mismatches, limiting a single retained-token
opportunity to three guesses: at most `3/255`, approximately `1.18%`, without
additional information. Consequently this chain is pre-authentication but has
high attack complexity and a deployment-state prerequisite.

## Static confirmation

The exact firmware `httpd` retains both relevant mechanisms:

- the IFTTT setup path generates the short token from `rand() % 0xff`, stores
  its octal representation in `ifttt_stoken`, and stores uptime in
  `ifttt_timestamp`;
- `gen_IFTTTtoken` at `0x8c9ac` computes current uptime minus the stored value
  and rejects only when the signed result exceeds 120. A post-reboot negative
  result therefore passes the age check;
- unlike the historically disclosed implementation, this build counts token
  mismatches and clears `ifttt_stoken` and `ifttt_timestamp` after the retry
  limit, preventing exhaustive enumeration of all 255 values.

## Dynamic confirmation

The rehosted guest was placed in the post-reboot state with a retained short
token of `0` and a stored generation uptime greater than current uptime. No
administrator cookie was supplied to this request:

```http
GET /get_IFTTTtoken.cgi?shortToken=0 HTTP/1.1
User-Agent: asusrouter-Windows-IFTTT-1.0
```

The exact firmware returned HTTP 200, `error_status: 0`, and an
administrator-equivalent IFTTT token. Supplying that recovered token as the
`asus_token` cookie to an otherwise identical multipart upload caused the exact
firmware handler and BusyBox `tar` to create:

```text
/tmp/friday-proof/asus-http-marker
FRIDAY_ASUS_HTTP_PROOF
```

The marker SHA-256 is
`4dede3e8b04d5ad2b7dd04627ec6cfc303154e50851d86357ea605a7f1cdf6be`.
No normal administrator login occurred in this chain.

Preserved evidence is under
`known_firmware/emulation/ASUS_RT-AX82U/preauth-chain-2026-07-14/`:

```text
e4cedb8edbae7168d45eed507a0945c147066931b99d21c04d8eb4c8917d1b3c  GREENHOUSE_STDLOG.preauth
4dede3e8b04d5ad2b7dd04627ec6cfc303154e50851d86357ea605a7f1cdf6be  asus-http-marker
b6928e1d193cd2c34b68af8179386d246710228a7abe99060a8b1b59f2262419  trace.preauth.log
```

## Relationship to public prior art

CVE-2022-35401 / TALOS-2022-1586 publicly describes the original RT-AX82U
IFTTT token weakness in firmware `3.0.0.4.386_49674`. Therefore the
authentication-bypass component must not be claimed as a new zero-day. The new
finding remains the server-certificate TAR-symlink arbitrary write. The report
may describe the combined impact as a conditional pre-authentication chain,
with the prerequisites and probability above stated prominently.
