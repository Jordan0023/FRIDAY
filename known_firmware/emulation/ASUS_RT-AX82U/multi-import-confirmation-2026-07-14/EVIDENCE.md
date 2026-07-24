# RT-AX82U additional importer confirmation

## Target and containment

- Firmware: ASUS RT-AX82U `3.0.0.4.388_25101`
- Firmware SHA-256: `00e344c92be2eceb43e3bbd3820c652b11c99f572adfe4bf5cb18c16df2aa916`
- Guest: exact extracted firmware rootfs under QEMU/Greenhouse
- Network: Docker internal-only network `friday-asus-proof-net`
- Authentication: existing synthetic firmware-issued IFTTT token in the lab guest
- Effect: marker creation only below `/tmp/friday-proof`

## IPsec server-certificate importer

An authenticated multipart request to
`POST /upload_server_ipsec_cert.cgi` supplied a bounded TAR archive containing
a relative symlink and marker member. The exact firmware handler invoked the
archive extraction path and created:

```text
/tmp/friday-proof/asus-http-marker
```

The marker SHA-256 is
`4dede3e8b04d5ad2b7dd04627ec6cfc303154e50851d86357ea605a7f1cdf6be`.
The HTTP client timed out waiting for a response, but the marker existed and
the firmware `httpd` process remained alive.

Static control flow independently identifies the cause in
`usr/lib/libwebapi.so`:

- exported handler `upload_server_ipsec_cert_cgi` at `0x5ba4`;
- fixed archive `/tmp/server_ipsec_file/server_ipsec.tgz`;
- extraction command `tar -xzf %s -C %s` built at `0x5c3c`-`0x5c68`;
- no pre-extraction rejection of symlink or traversal members.

## User-icon backup importer

An authenticated multipart request to
`POST /upload_all_usericon.cgi` supplied a bounded `.bak` archive whose
relative symlink escapes the `/jffs` extraction directory only into the
modeled `/tmp/friday-proof` destination. The exact firmware returned HTTP 200
and created the same marker outside `/jffs`.

The shared `upload_jffs_profile` function in `usr/lib/libwebapi.so` constructs
an `xzvf` TAR extraction command with destination `/jffs` at
`0xc0cc`-`0xc118`. The profile table includes `usericon`.

## Classification

Both routes have L5 reproducible technical effects and are confirmed
authenticated arbitrary-file-write vulnerabilities in this firmware. Under
the repository policy they are not labeled confirmed zero-days because they
require an administrator-equivalent token. Public searches on 2026-07-14 did
not find the exact IPsec route or `server_ipsec.tgz`; CVE-2024-0401 publicly
documents a related authenticated OpenVPN upload issue, so root-cause novelty
also requires vendor/CNA adjudication.

## Direct unauthenticated controls

The identical marker-only archives were subsequently replayed against both
routes without an `asus_token` cookie:

- `POST /upload_server_ipsec_cert.cgi`: connection closed, no marker created;
- `POST /upload_all_usericon.cgi`: connection closed, no marker created.

After each request the firmware HTTP listener still returned HTTP 200 for its
health check. These controls show that neither importer directly reaches its
extraction callback without an administrator-equivalent authorization token.
The separately documented residual IFTTT short-token behavior can conditionally
supply such a token without a normal login, but that authentication weakness is
public prior art and has configuration, reboot-state, and three-guess
prerequisites.

## Authorization-chain matrix

The user-icon importer was used as the fast control for an additional bounded
authorization matrix. No marker was created for any of the following
unauthenticated variants:

- dot, duplicate-slash, encoded-suffix, path-info, and semicolon route forms;
- invalid, duplicated-invalid, Basic, and Bearer credentials;
- `X-Forwarded-For: 127.0.0.1` and a localhost `Referer`;
- ASUS mobile-app User-Agent;
- `X-HTTP-Method-Override`;
- factory/onboarding state (`x_Setting=0`).

The IPsec and user-icon marker archives were both explicitly tested in the
factory/onboarding state and remained blocked. The synthetic emulator was
already in that state before this control, and the value was preserved.

With a valid synthetic firmware session, the user-icon route accepted a
request carrying an attacker-site `Origin` and `Referer` and created the
marker. This confirms that the server callback does not enforce an Origin or
Referer check. It is only a conditional CSRF lead: an actual browser must also
send the administrator cookie on a cross-site multipart POST. The current
binary contains no `SameSite` cookie attribute string, but modern browser
default-SameSite behavior may still prevent that cookie transmission.

## Conditional IFTTT chain reproduction

The retained post-reboot state was recreated in the isolated guest with short
token `0` and a stored generation uptime greater than current uptime. With no
cookie and no administrator credentials, this request returned
`error_status=0` and a non-empty 31-byte IFTTT token:

```http
GET /get_IFTTTtoken.cgi?shortToken=0 HTTP/1.1
User-Agent: asusrouter-Windows-IFTTT-1.0
```

The recovered value was not printed or preserved. Supplying it directly as the
`asus_token` cookie to `POST /upload_all_usericon.cgi` caused the exact firmware
to create the bounded marker with SHA-256
`4dede3e8b04d5ad2b7dd04627ec6cfc303154e50851d86357ea605a7f1cdf6be`.
The synthetic retained short-token and timestamp values were cleared after the
test. This confirms the conditional no-credentials chain for the user-icon
importer as well as the previously documented OpenVPN importer.

Preserved files:

- `asus-http-marker`
- `ipsec.headers`
- `usericon.headers`
- `trace.e2e.log`
