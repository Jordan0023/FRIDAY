# Internal zero-day assessment record — ASUS RT-AX82U

- Assessment time: `2026-07-14T11:06:28Z`
- Firmware: `3.0.0.4.388_25101`
- Firmware SHA-256: `00e344c92be2eceb43e3bbd3820c652b11c99f572adfe4bf5cb18c16df2aa916`
- External submission: none authorized or performed

## Current decision

**Not a confirmed zero-day under the revised repository policy.** The finding
is an L5-confirmed authenticated vulnerability: a multipart request reached the
exact firmware handler, invoked firmware BusyBox `tar`, and created the bounded
marker outside the extraction directory. Direct exploitation requires a remote
administrator session. The demonstrated pre-authentication chain relies on the
publicly known CVE-2022-35401 IFTTT weakness, so it does not satisfy the policy's
novel pre-authentication requirement. The technical evidence remains valid;
only the zero-day classification changes.

## Technical evidence reproduced on 2026-07-14

The repository proof was executed against the exact firmware BusyBox:

```text
pivot
pivot/root
CONFIRMED: firmware BusyBox escaped -C and wrote root crontab path:
/tmp/asus-rt-ax82u-tar-proof/runtime/var/spool/cron/crontabs/root
```

The proof wrote only inside the modeled tree below `/tmp`. The proof script
SHA-256 was `afa860566f2a4bff11fe562463fc5c6912c046178d569e6c333e3156d3dad98f`.

An isolated Greenhouse run then rehosted the exact ARM `httpd`. After the first
dependency-discovery cycle, the service returned HTTP 200 twice on
`172.21.0.2:80`, passed Greenhouse's well-formed-page check, and later returned
HTTP 200 on both `172.21.0.2:80` and `192.168.1.1:80`. The run used Docker
network isolation and reached its ten-minute bound. Greenhouse stopped each
probe container after its health check, so the multipart replay was not sent
before teardown.

The successful scratch guest was subsequently exported and relaunched on an
internal-only Docker network. A multipart request to
`upload_server_ovpn_cert.cgi` reached the firmware route and parser. The syscall
trace recorded:

- lookup of `/www/upload_server_ovpn_cert.cgi`;
- creation of `/tmp/server_ovpn_file`;
- processing of `upload_server_ovpn_cert_temp`; and
- execution of the handler's `/bin/rm` cleanup child.

The parser attempted to seek backward on the emulated request socket. QEMU
returned `ESPIPE` (`Illegal seek`), after which the archive was not written and
the peer closed without an HTTP response. No proof marker was created. This is
route/trigger evidence, but it is not an L5 security-effect reproduction and
must not be counted as one.

## End-to-end confirmation

The failed replay was diagnosed on `2026-07-14`. `ESPIPE` was not the terminal
cause: the handler continues after the failed seeks. The replay was missing the
firmware-issued `asus_token`, and the deliberately bounded symlink destination
did not yet exist. After acquiring the token from the emulated firmware and
pre-creating only `/tmp/friday-proof` in the disposable guest, a standard
multipart upload produced HTTP 200 and:

```html
<script>parent.callback_upload_cert(1);</script>
```

The exact ARM `httpd` accepted the request and the exact firmware BusyBox
executed `/bin/tar`. The archive SHA-256 was
`935f99f89c19f3549762e0ef7b46341ba0edb76a71008fa661a272dbf0cf7c44`.
The resulting file was `/tmp/friday-proof/asus-http-marker`, outside
`/tmp/server_ovpn_file`, with SHA-256
`4dede3e8b04d5ad2b7dd04627ec6cfc303154e50851d86357ea605a7f1cdf6be`
and content:

```text
FRIDAY_ASUS_HTTP_PROOF
```

The handler subsequently removed its extraction directory while the marker
remained. Preserved evidence is under
`known_firmware/emulation/ASUS_RT-AX82U/e2e-confirmation-2026-07-14/`.

## Authentication boundary follow-up

No-cookie and invalid-cookie uploads were rejected without creating a marker.
The TAR flaw therefore requires an administrator session when exploited
directly. A conditional pre-authentication chain was also reproduced using the
current firmware's residual IFTTT short-token behavior: with IFTTT/Alexa state
retained across a modeled reboot, an unauthenticated request recovered an
administrator-equivalent token and completed the same TAR proof. This requires
a correct guess within three attempts over 255 values (at most about 1.18%) and
the specific prior-configuration/reboot state. The IFTTT component is related
to public CVE-2022-35401 and is not claimed as a zero-day. See
`PREAUTH_CHAIN_CONFIRMATION_2026-07-14.md`.

## Public-prior-art search

Searches performed on `2026-07-14`:

- `"upload_server_ovpn_cert.cgi" vulnerability`
- `"server_ovpn.tgz" ASUS vulnerability`
- `ASUS OpenVPN "TAR symlink" vulnerability`
- `ASUS RT-AX82U OpenVPN server certificate arbitrary file write`
- ASUS security advisories and RT-AX82U firmware history
- CVE/NVD searches for the route, product, upload flow, and TAR-symlink primitive

No result described this ASUS route and root cause. Results included unrelated
generic TAR-library symlink vulnerabilities and ASUS documentation for the
OpenVPN server certificate feature. ASUS firmware `25098` release notes say the
VPN configuration upload interface received stronger validation and directory
handling, but the relevant `httpd` and `libwebapi.so` in `25098` and `25101`
are byte-identical according to the cross-version analysis.

Sources checked:

- https://www.asus.com/security-advisory
- https://www.asus.com/us/supportonly/rt-ax82u/helpdesk_bios/?model2Name=RT-AX82U
- https://www.asus.com/uk/support/faq/1008713/
- https://nvd.nist.gov/
- https://www.cve.org/

## Confirmation chain

```text
authenticated multipart request
  -> upload_server_ovpn_cert.cgi
  -> firmware upload parser
  -> upload_server_ovpn_cert_cgi
  -> firmware BusyBox tar
  -> /tmp/friday-proof/asus-http-marker outside the extraction directory
```

This chain was reproduced in one bounded, internal-only Docker guest on
`2026-07-14`.

Vendor or CNA contact is not required by project policy. The final report must
retain the caveat that a public novelty search cannot exclude an unknown
private or embargoed duplicate.
