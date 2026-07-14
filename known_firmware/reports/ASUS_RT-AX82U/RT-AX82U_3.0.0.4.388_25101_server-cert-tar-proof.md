# RT-AX82U OpenVPN server-certificate archive extraction proof

## Verdict

**Confirmed vulnerability primitive:** an archive supplied to the OpenVPN
server-certificate upload flow can write outside its intended extraction
directory by combining a symlink member with a later file below that symlink.

**Zero-day status:** **not confirmed under the revised repository policy.**
The TAR flaw is L5-confirmed but directly requires a remote authenticated
administrator. Its demonstrated pre-authentication chain relies on public
CVE-2022-35401 and therefore does not qualify as a novel pre-authentication
path. Public records describe
CVE-2024-0401 as authenticated command execution through a crafted client OVPN
profile. This finding instead reaches a server-certificate TAR extractor,
uses a TAR symlink rather than shell metacharacters, and affects RT-AX82U,
which is absent from the published CVE-2024-0401 model lists. Cross-version
comparison also shows that the mechanism remains in firmware released long
after the CVE-2024-0401 advisory. These distinctions support a separate root
cause. It remains a confirmed, apparently novel authenticated vulnerability
primitive, but must not be labeled a confirmed zero-day. This public-novelty
assessment cannot exclude an unknown private or embargoed duplicate.

## Target

- Product: ASUS RT-AX82U
- Firmware: `3.0.0.4.388_25101`
- Firmware SHA-256: `00e344c92be2eceb43e3bbd3820c652b11c99f572adfe4bf5cb18c16df2aa916`
- `libwebapi.so` SHA-256: `3e2a792c32f2905b4ac5c65fc2ac5f16673c7ab93a64378078c0bc2bdf3e73c0`
- BusyBox SHA-256: `3971de53a923cf334dac4dd10ad5aac024c60717df3d6b1c4d27eab3b151346c`
- BusyBox version: `1.24.1`

## Static trace

The HTTP route table entry at `httpd` virtual address `0xb664c` contains
`upload_server_ovpn_cert.cgi*`. That same entry assigns `0x28628` as its POST
body parser and `0x2baa8` as its response handler. The response handler calls
the exported `upload_server_ovpn_cert_cgi` function in `usr/lib/libwebapi.so`
at virtual address `0x5740` (488 bytes).

The POST parser at `0x28628` parses the multipart boundary and
`Content-Disposition`, creates `/tmp/server_ovpn_file`, opens
`/tmp/server_ovpn_file/server_ovpn.tgz`, and copies the request body into that
file in chunks. Its embedded strings include `name="import_cert_file"`, the
fixed archive path, and `upload_server_ovpn_cert_temp`.

The function uses fixed paths, so its `rm` invocation is not command injection.
After receiving `/tmp/server_ovpn_file/server_ovpn.tgz`, however, it builds and
executes:

```text
tar -xzf /tmp/server_ovpn_file/server_ovpn.tgz -C /tmp/server_ovpn_file
```

No archive-member canonicalization or symlink rejection occurs before the
firmware's BusyBox `tar` processes the archive. The function subsequently moves
expected certificate names to `/jffs/openvpn/` and restarts OpenVPN, but that
happens after extraction and does not constrain files already written by TAR.

## Dynamic proof

The first proof archive had two ordered members:

1. `link`, a symlink to `../../`
2. `link/symlink-marker`, a regular file containing `ASUS_SYMLINK_PROOF`

Executing the exact firmware BusyBox under QEMU with `-C` set to an isolated
directory produced `/tmp/symlink-marker`. This demonstrates that the second
member follows the first member's symlink and escapes the extraction root.
The direct `../../file` variant was also tested and correctly sanitized; the
symlink sequence is required.

A second non-destructive proof modeled the firmware's runtime paths. From an
extraction directory named `/tmp/server_ovpn_file`, the archive created a
symlink to `../var/spool/cron/crontabs` and then wrote `pivot/root`. The exact
firmware BusyBox consequently created the modeled root crontab outside the
extraction directory. Firmware strings independently establish that `rc`
creates `/var/spool/cron/crontabs` and starts `crond`, while BusyBox identifies
that directory as its default crontab directory.

## Cross-version evidence

The vulnerable implementation is not confined to one historical image:

- RT-AX82U `3.0.0.4.388_25004`, released 2024-10-09, contains the same fixed
  archive path and `tar -xzf %s -C %s` extraction sequence in
  `libwebapi.so`.
- RT-AX82U `3.0.0.4.388_25098`, released 2025-10-28, has `libwebapi.so`
  SHA-256 `3e2a792c32f2905b4ac5f2ac5f16673c7ab93a64378078c0bc2bdf3e73c0`
  and `httpd` SHA-256
  `9f9f0aaaab17bacce5895fab092f0578be2e776159845e660e8494633e90c6a7`.
- RT-AX82U `3.0.0.4.388_25101`, released 2026-01-15, contains byte-identical
  copies of both binaries. It therefore retains the same handler and TAR
  extraction behavior as `25098`.

CVE-2024-0401 was published in May 2024. Its public NVD description concerns a
crafted custom OVPN profile, and the ASUS advisory instructs users to avoid
uploading an OVPN file to the OpenVPN client. The route, input format,
exploitation primitive, and published affected-model list differ from this
server-certificate archive path.

Run the non-destructive reproducer:

```bash
bash known_firmware/reports/ASUS_RT-AX82U/pocs/rt_ax82u_server_cert_tar_symlink_poc.sh
```

Expected final output:

```text
CONFIRMED: firmware BusyBox escaped -C and wrote root crontab path: .../var/spool/cron/crontabs/root
```

## Security impact and remaining validation

The demonstrated primitive is arbitrary file write relative to the privileges
of the router HTTP service. The route name's trailing `*` is consistent with
ASUS's protected management handlers, and the UI exposes it from the OpenVPN
server administration page, so the current assessment is **remote,
authenticated administrator required when exploited directly**. Emulation
confirmed that requests with no cookie or an invalid token do not reach TAR.
The authenticated multipart format and session enforcement were both exercised
against the exact rehosted service.

### Conditional pre-authentication chain

A separate bounded demonstration recovered an administrator-equivalent token
from `get_IFTTTtoken.cgi` without a login when the guest modeled an IFTTT/Alexa
integration configured before a router reboot. That token completed the TAR
proof end to end. The current firmware limits the retained short token to three
guesses from 255 possibilities, so this is conditional, probabilistic
pre-authentication exploitation with high attack complexity—not a universal
unauthenticated path. The IFTTT component is related to public
CVE-2022-35401/TALOS-2022-1586 and is not itself claimed as new. See
`PREAUTH_CHAIN_CONFIRMATION_2026-07-14.md` for the prerequisites, static control
flow, dynamic result, and evidence hashes.

On typical ASUSWRT deployments the management service and cron daemon run with
root-equivalent privileges. The confirmed ability to replace root's crontab
provides a direct command-execution path at the next cron evaluation. The
non-destructive proof writes only into a modeled directory below `/tmp`; it
does not alter the workstation's crontab or attempt persistence. Full-daemon
HTTP emulation was attempted in a read-only container, but `httpd` exits without
the router's NVRAM and hardware services. The route-table and multipart-parser
trace therefore establish HTTP reachability statically, while the exact
firmware BusyBox establishes the write primitive dynamically.

On 2026-07-14, a bounded Greenhouse retry progressed further: the exact ARM
`httpd` returned HTTP 200 on the isolated guest interfaces and passed a
well-formed-page check. Greenhouse stopped the transient probe container after
its health check, before the multipart proof could be replayed. This confirms
that the daemon can be rehosted but does not yet join the HTTP request and
archive escape into one L5 run. See
`INTERNAL_ZERO_DAY_CONFIRMATION_2026-07-14.md` for the dated decision record.

The exported guest was then relaunched on an internal-only network. An initial bounded
multipart replay reached the route and upload parser: the trace showed creation
of `/tmp/server_ovpn_file`, processing of `upload_server_ovpn_cert_temp`, and
the handler's cleanup command. QEMU returned `ESPIPE` when the parser sought
backward on the emulated request socket, so the archive was not written and no
marker was created. This closes the route-reachability question in emulation,
but that replay did not yet provide an L5 end-to-end proof.

The failure was subsequently resolved. The seek error was non-terminal; the
missing requirements were the firmware-issued `asus_token` and an existing
bounded symlink destination. A canonical authenticated multipart replay in the
same isolated guest wrote `server_ovpn.tgz`, invoked the exact firmware
BusyBox `tar`, and created `/tmp/friday-proof/asus-http-marker` outside the
extraction directory. The marker contains `FRIDAY_ASUS_HTTP_PROOF` and has
SHA-256 `4dede3e8b04d5ad2b7dd04627ec6cfc303154e50851d86357ea605a7f1cdf6be`.
The handler removed `/tmp/server_ovpn_file` afterward while the marker remained.
This closes the L5 end-to-end requirement. See the internal confirmation record
and preserved emulator evidence for the complete chain and hashes.

## Other candidate disposition

- ASUS DDNS candidates: no attacker-controlled value was proven to reach a
  command sink in this pass.
- ASUS fixed-path cleanup commands: rejected as command-injection findings.
- TP-Link Archer C5400X `cgi-bin/luci` candidates: generic LuCI framework routes;
  no vulnerable source-to-sink path was established.
- GL-MT5000, RAXE500, and Archer AX21: no route candidates from this scan.
