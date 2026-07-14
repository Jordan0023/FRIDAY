# RT-AX82U historical-vulnerability regression audit

## Scope

- New target: ASUS RT-AX82U `3.0.0.4.388_25101`
- Historical comparison: RT-AX82U GUNDAM `3.0.0.4.386_49559`
- New firmware SHA-256: `00e344c92be2eceb43e3bbd3820c652b11c99f572adfe4bf5cb18c16df2aa916`
- Old `httpd` SHA-256: `c4e30e723e5d51410facd848a0595c25fdc88ad62d20a789398c4ad137ff7087`
- New `httpd` SHA-256: `9f9f0aaaab17bacce5895fab092f0578be2e776159845e660e8494633e90c6a7`
- Old `cfg_server` SHA-256: `7fe8b7365e7365b197132619548994097393a65d1ebc3a36148d6b74c34a0b5d`
- New `cfg_server` SHA-256: `ab815057f690137948456f93298cbad9108258beb49f90da50b4042feedc705e`

This pass mapped public historical RT-AX82U weaknesses into the current
firmware and required a novel, reproducible pre-authentication effect before
promotion to a zero-day candidate.

## Results

### CVE-2022-26376 — HTTP URL-decoder memory corruption

Five bounded malformed percent-encoding cases were sent to the exact rehosted
`25101` HTTP service, including terminal `%` and one-nibble `%a` values in both
paths and query strings. Responses were bounded HTTP 200/404 results and the
listener remained healthy. No crash, memory-corruption signal, or behavioral
regression was reproduced.

Disposition: **negative dynamic evidence; not a candidate**.

### CVE-2022-35401 — IFTTT authentication bypass

The current firmware retains a conditional post-reboot timestamp weakness, but
adds a three-mismatch limit that clears the retained short-token state. The
conditional chain is documented separately. Its authentication component is
public prior art and cannot qualify as a novel zero-day path.

Disposition: **public known weakness/variant; not a zero-day candidate**.

### CVE-2022-38105 — `cfg_server` `cm_processREQ_NC` disclosure

The `cm_processREQ_NC` handler and unauthenticated key-exchange surface remain
present in the current binary. The old and new binaries are not identical.
This pass did not establish a current out-of-bounds disclosure or extract
sensitive bytes from `25101`.

Disposition: **requires deeper function-level diff; no confirmed effect**.

### CVE-2022-38393 — `cfg_server` ConnDiag underflow/DoS

The new `cm_processConnDiagPktList` function at `0x58834` still loads the
received byte count and subtracts `0xc` before comparing it with the packet's
declared length. That initially appeared to match the public underflow pattern,
although the exact public finding used firmware `386_49674`.

Deeper caller analysis found the missing evidence: the current UDP receive
handler at `0x1efe0` compares the actual received length with `0xb` at
`0x1f3ec` and only reaches the subtraction/queue path when the length is greater
than 11 bytes. Packets of 11 bytes or fewer take the explicit
`error on received size` path. Therefore, the eight-byte public trigger cannot
reach `cm_processConnDiagPktList` on `25101`. The downstream AES routine still
lacks its own defensive length check, but the network caller now enforces the
required 12-byte minimum.

The daemon was subsequently brought up in the isolated Greenhouse guest on both
TCP and UDP port 7788. The emulation required explicit model scaffolding:

- NVRAM values for the interface MAC, firmware check, and debug controls;
- an ephemeral RSA keypair at `/etc/cfg_mnt/{key,pubkey}.pem`;
- a dummy `br0` interface with `192.168.50.1/24`; and
- two runtime-only branch changes in a copy of `cfg_server` to model a supported
  AiMesh capability and a successful hardware authorization check. The original
  extracted binary was not changed.

The exact public eight-byte trigger (`00 00 00 06 ff ff ff fc`) was delivered
over UDP from a separate container. `recvfrom` returned 8, after which the new
minimum-length check rejected it. The process and both listeners remained alive
five seconds later, and QEMU recorded no `SIGSEGV` or `SIGABRT`. A bounded
adjacent corpus then sent
4-, 8-, and 12-byte packets for opcodes 1 through 8 over both TCP and UDP (64
total sends). The daemon and both listeners again remained alive after five
seconds with no fatal signal in the syscall trace.

The runtime authorization/capability changes reduce whole-system fidelity, but
they do not alter the UDP receive or packet-processing instructions. The caller
guard is a code-level fix for the published eight-byte trigger, independently
of `group_key_ready`. Increasing the packet to 12 bytes avoids the underflow;
keeping it below 12 bytes hits the guard. Consequently there is no improved
packet for this same root cause without first finding a distinct way to bypass
the new guard.

Disposition: **published CVE trigger blocked by a current caller-side fix; not
reproduced and not a novel candidate**.

### Distinct pre-authentication `cfg_server` search

The current TCP opcode table was recovered from `.data` at `0xc0488`. Its
unauthenticated key-exchange handlers include `REQ_KU` (opcode 1, handler
`0x5c6a8`) and `REQ_NC` (opcode 3, handler `0x5ccb8`). Review of the newer
`REQ_NC` handler found an explicit `master_key_length == 0x20` comparison at
`0x5d510`. This blocks the undersized AES-256 key oracle described in
CVE-2022-38105 before the key allocation and encryption operations.

A bounded TCP parser corpus tested opcodes 1, 3, 4, 5, and 8 with declared
payload lengths of 0, 1, 4, 11, 12, 31, 32, 33, 255, 256, 2047, 2048, 4096,
`0x7fffffff`, and `0xffffffff`. Each message was split after five bytes to also
exercise fragmented-header handling. All 75 connections were reset or rejected
individually; the daemon and both port 7788 listeners remained alive afterward.

Disposition: **no distinct pre-authentication vulnerability confirmed by this
TCP parser pass**.

### Cross-model transfer: RT-AX92U WebDAV SQL injection

ZDI-23-1166 / CVE-2023-35720 describes an unauthenticated SQL injection in the
RT-AX92U `lighttpd` `mod_webdav.so` component. This class is directly applicable
for review because RT-AX82U `25101` contains the same Lighttpd 1.4.39 WebDAV
stack, SQLite support, and AiDisk/WebDAV configuration tooling.

The following modules were compared:

- RT-AX92U `384_6063` `mod_webdav.so`: SHA-256
  `47752a4553687f27b24a17307f1bbcb507aca6fb67a984eb9b2af2b830d00c48`;
- RT-AX92U `388_23809` `mod_webdav.so`: SHA-256
  `64529f816f78677715cd12a51a30499efcc9c9ce973db61c00822d3641e677bc`;
- RT-AX82U `388_25101` `mod_webdav.so`: SHA-256
  `a940048ebfdacdf9541369a2779cc6e143c4b480a10c164b684ec17b876556a5`.

The current RT-AX82U module still contains request-path SQL templates including
`%s WHERE PATH = '%s'` and `%s WHERE PATH = '/tmp%s'`. It also imports prepared
statement and bind APIs for other WebDAV operations, so the templates alone do
not establish that attacker-controlled path text reaches SQLite without
escaping.

`write_webdav_conf` successfully produced a configuration with `mod_webdav`
enabled. A startup trace also exposed an ASUS-specific launcher restriction:
the binary rejects arbitrary `-f` paths and regenerates configuration only for
the `/tmp/lighttpd.conf` and `/tmp/uamsrv.conf` prefixes. To isolate WebDAV from
unrelated AiCloud module crashes, the generated-config target was bind-mounted
read-only over a minimal configuration. No executable or shared object was
modified.

With that harness, the original `lighttpd` and `mod_webdav.so` bound TCP port
18081 and initialized `/tmp/lighttpd/webdav.db` as UID/GID 65534. The database
contained the live WebDAV schemas:

- `properties(resource, prop, ns, value)` with a composite primary key; and
- `locks(locktoken, resource, lockscope, locktype, owner, depth, timeout)`.

Activating WebDAV globally in the minimal harness initially caused a null
dereference before an SQLite syscall. QEMU's GDB stub located it in libc
`strncmp`, called through Lighttpd `string_starts_with` from the current
`mod_webdav.so` request handler (module-relative return address `0x5990`). The
module was testing `/smb` against a route buffer that had not been populated.

The blocker was resolved without patching code by restoring ASUS's normal
`mod_alias` route and limiting WebDAV activation to the generated model path,
`/RT-AC68U`. A valid HTTP/1.1 request with `Host` then reached a stable WebDAV
handler. Restoring the normal `mod_aicloud_auth` and `mod_aidisk_access` modules
produced the authentic pre-authentication behavior:

- `OPTIONS /RT-AC68U/` advertised the DAV methods;
- ordinary unauthenticated `PROPFIND` returned `401 Unauthorized` with the
  `webdav` Basic realm;
- a path containing a percent-decoded quote was rejected with status `451`
  before database-backed handling; and
- the SHA-256 of `webdav.db` remained
  `ccfcd9f05e68e0e1e3b5783893dd74fdb06b59622a1da05a147d3f663f908295`
  across the baseline and quoted-path probes.

Disposition: **published cross-model SQL-injection lead blocked by current
pre-database authentication/input validation; not reproduced and not a novel
candidate**.

### Current token and management endpoints

Unauthenticated requests were made to:

- `asusrouter_request_token.cgi`
- `asusrouter_request_access_token.cgi`
- `endpoint_request_token.cgi`
- `get_eptoken.cgi`
- `get_Nonce.cgi`
- `check_Auth.cgi`
- `appGet.cgi`

Token endpoints returned explicit error states or empty token material.
`appGet.cgi` redirected to login. `check_Auth.cgi` returned a superficial
`asus_auth: OK` response in the synthetic setup state but issued no cookie and
did not cross the protected-handler boundary.

Disposition: **no token disclosure or authentication bypass demonstrated**.

## Scanner result

The authentication-first advanced scan promoted zero candidates. It reported
route/sink co-location and service inventory, but no new route-local,
pre-authentication source-to-sink path with a reproducible security effect.

## Decision

**No new confirmed zero-day was found in this regression pass.** The published
`cfg_server` ConnDiag trigger is blocked by a current minimum-length check. The
RT-AX92U WebDAV SQL-injection transfer was also exercised end to end after its
request-context blocker was resolved. The current RT-AX82U route requires
authentication for ordinary WebDAV methods and rejects a decoded quote before
database-backed handling; the database stayed unchanged. It is therefore not a
confirmed vulnerability on `25101`.
