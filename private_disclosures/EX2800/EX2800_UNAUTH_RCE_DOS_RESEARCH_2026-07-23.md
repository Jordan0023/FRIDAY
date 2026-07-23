# Apparent zero-day unauthenticated RCE in NETGEAR EX2800 V1.0.1.84

Date: 2026-07-23

## Executive summary

An apparent previously undisclosed vulnerability in NETGEAR EX2800 firmware
V1.0.1.84 allows an unauthenticated client that can reach the management
service while the extender is in its factory-unconfigured state to execute
arbitrary operating-system commands as root.

The complete chain was reproduced over HTTP in network-isolated firmware
emulation:

1. An unauthenticated setup request causes `webproc` to create the one-shot
   `/var/upgUnauth` authentication-bypass marker.
2. A request to the original `webupg` consumes that marker and succeeds without
   a valid administrator session.
3. The `shell` action accepts an attacker-controlled `cmd` value, appends
   `2>&1`, and passes it to `popen`.
4. A harmless command executed successfully and its stdout was reflected in
   the HTTP response.

No valid administrator credential or token was used. A syntactically present
dummy `sessionid` cookie was required to enter the relevant parsing path.

Public-record research performed on 2026-07-23 found no advisory or CVE
describing this exact
`factory-unconfigured -> /var/upgUnauth -> webupg shell -> popen` chain.
Existing EX2800 CVE-2026-0407 and CVE-2026-0408 entries cover different issues
and versions before 1.0.1.82. The affected behavior remains reproducible in
V1.0.1.84, released on 2026-04-24.

Accordingly, this report classifies the issue as an **apparent zero-day
unauthenticated root RCE confirmed in firmware emulation**. “Apparent” records
the unavoidable limitation that public searching cannot exclude a confidential
vendor report, embargoed advisory, or reserved CVE. Physical-router testing and
vendor acknowledgment are not definitional requirements for zero-day status,
but both would strengthen affected-product validation.

## Result

End-to-end unauthenticated root command execution is confirmed in
network-isolated firmware emulation. The chain uses the factory-unconfigured
state to create a one-shot authentication-bypass marker, consumes that marker
in the original `webupg`, reaches `UPGCGI_WebShell`, invokes `popen`, and
reflects harmless command output over HTTP.

Persistent unauthenticated DoS was not confirmed. Technical reproduction alone
does not establish novelty, but the dated public-record review below found no
matching disclosure and supports classification as an apparent zero-day.

## Classification

- Vulnerability class: authentication bypass chained with OS command injection
- Authentication required: no valid administrator authentication
- Privileges gained: root
- User interaction: none
- Confirmed attack surface: management HTTP service in factory-unconfigured
  state
- Confirmation level: end-to-end firmware emulation
- Novelty classification: apparent zero-day based on the public record checked
  on 2026-07-23
- Physical-device validation: not performed
- Persistent unauthenticated DoS: not confirmed

## Public-record and novelty assessment

The following public records were reviewed:

- NETGEAR firmware V1.0.1.84 release notes:
  <https://kb.netgear.com/000070691/EX2800-EX3110-EX5000-EX6110-Firmware-Version-1-0-1-84>
- January 2026 NETGEAR Security Advisory:
  <https://kb.netgear.com/000070442/January-2026-NETGEAR-Security-Advisory>
- NVD CVE-2026-0407:
  <https://nvd.nist.gov/vuln/detail/CVE-2026-0407>
- NVD CVE-2026-0408:
  <https://nvd.nist.gov/vuln/detail/CVE-2026-0408>

CVE-2026-0407 and CVE-2026-0408 list EX2800 versions before 1.0.1.82 and
describe different authenticated or improper-authentication behavior. Neither
record describes the one-shot unconfigured-state marker, the `shell` action,
the `twmode` key, or unauthenticated `popen` command execution demonstrated
here. Searches for EX2800 together with `webupg`, `twmode`, unauthenticated RCE,
and V1.0.1.84 returned no matching public disclosure.

This supports zero-day treatment at the time of discovery, provided the search
date and results are preserved. It does not prove that NETGEAR or another
researcher has never received a confidential duplicate.

Firmware:

- Model: NETGEAR EX2800
- Version: V1.0.1.84
- Firmware SHA-256:
  `8d9a63c1224b5d8137833b861e9d0ba44a1202a892d927f942cf1e740cf02163`
- `usr/www/cgi-bin/webupg` SHA-256:
  `2f2b6eec48e73450a433a3b755e0b06448038e34415bc3184a5b7773cedc882d`

## Root cause and confirmed exploit chain

Ghidra decompilation identified the following behavior:

1. `UPGCGI_WebShell` at virtual address `0x12d34` obtains the query variables
   `key` and `cmd`.
2. It requires the literal key `twmode`.
3. It formats the supplied command as `%s 2>&1` and passes it to `popen`.
4. `UPGCGI_CheckAuth` at `0x13730` checks `/var/upgUnauth`; when present it
   unlinks the file and returns success without normal authentication.
5. `WEB_GetCgiVars` in `usr/www/cgi-bin/webproc` at `0x404670` contains a
   branch that creates `/var/upgUnauth` while `/var/unconfig` exists and a
   request value matches one of:
   `html/index_basic.htm`, `apupconn`, or `BRS_haveBackupFile`.

This creates the confirmed chain:

`unconfigured setup request -> /var/upgUnauth -> webupg shell action -> popen`

The command sink and bypass-marker logic are direct code evidence. A network
request reaching the marker-creation branch has now been reproduced.

Required request-state observations:

- `/var/unconfig` must exist.
- `HTTP_COOKIE` must be syntactically present, but the reproduced value did not
  represent a valid authenticated session.
- A setup-page value matching `html/index_basic.htm` reaches the branch.
- The branch removes `/var/unconfig` and creates `/var/upgUnauth`.

## Dynamic validation

Testing was performed only inside a Docker container with `--network none`,
using QEMU MIPS user emulation, PRoot, the extracted firmware root, and a
minimal message-bus compatibility shim.

The root filesystem was placed into the firmware's unconfigured state by
creating `/var/unconfig` in a disposable copy. The original `/usr/bin/logic`
configuration/message daemon was restored with only hardware-init
accommodations: a narrowly scoped MT7628 MTD-ioctl shim and two control-flow
changes that prevent unavailable optional hardware modules from aborting the
daemon. Configuration and message functions were not stubbed.

With the original `mini_httpd`, `webproc`, and restored `logic` active, an HTTP
setup request with a syntactically present but invalid dummy `sessionid` cookie
produced:

```text
unconfigured_state_present=true
setup_trigger_status=200
upgUnauth_created=true
```

This confirms the remote setup-to-bypass-marker bridge. Prior negative tests
omitted `HTTP_COOKIE`; `webproc`'s `My_getenv`/error path crashed before
`WEB_GetCgiVars` reached the marker branch.

The follow-on POST to the original `webupg` returned HTTP 200 and entered the
CGI execution path, demonstrating that `mini_httpd` did not reject the request
at its password-file layer in this state. The first QEMU fault was mapped to
`strdup(getenv("QUERY_STRING"))`: this build of `mini_httpd` did not populate
`QUERY_STRING` for the urlencoded POST, and `webupg` does not check for NULL
before calling `strdup`.

A disposable compatibility patch substituting an empty string confirmed that
this was the immediate fault. The first version incorrectly bypassed `strdup`
and exposed a write to read-only storage in the in-place URL decoder; retaining
the original `strdup` removes that artifact. Supplying the action through a
real `QUERY_STRING` is cleaner and requires no binary change. With the original
binary and:

```
name=shell&key=twmode&cmd=echo%20FRIDAY_EX2800_UNCONFIGURED_RCE
```

the request consumed `/var/upgUnauth`, dynamically confirming entry through
the one-shot authentication bypass.

The next fault occurs after authentication in `UPGCGI_SendMsgPage`. It first
appeared to be an undersized stack mapping because the `memset` at file offset
`0x6128` faulted at the mapping boundary (`PC 0x3f677810`, return address
`0x40006130`). An expanded syscall trace established the real cause:
`UPGCGI_SendMsgPage` recursively calls itself when
`fopen("/proc/llconfig/model")` fails. Each recursion allocates approximately
10 KiB and eventually exhausts the otherwise healthy QEMU stack.

The emulation blocker is resolved without changing `webupg`: a read-only PRoot
bind maps a disposable file containing `EX2800` onto
`/proc/llconfig/model`. With that fixture, the original CGI returns normally
with status 42 and renders the complete response page. The harness exposes this
as `MODEL_FILE_BIND`; it adds:

```
-b "$MODEL_FILE_BIND:/proc/llconfig/model"
```

to the HTTP daemon's PRoot environment. A one-instruction experiment reducing
the response-buffer clear length was rejected because it treated the symptom
rather than the missing procfs dependency.

The active disposable `webupg` was restored byte-for-byte to the original
(SHA-256
`2f2b6eec48e73450a433a3b755e0b06448038e34415bc3184a5b7773cedc882d`).
The rejected stack experiment remains separately named
`webupg.emu-stack-test` in the disposable lab for diagnosis.

Accordingly:

- remote unauthenticated creation of the one-shot bypass: dynamically confirmed;
- HTTP reachability of the follow-on CGI: dynamically confirmed;
- arbitrary root command sink after the bypass: directly confirmed statically;
- one-shot bypass consumption by the original binary: dynamically confirmed;
- post-auth `UPGCGI_SendMsgPage` recursion/stack fault: resolved with a
  model-only procfs fixture;
- final command execution: dynamically reproduced through the isolated HTTP
  chain with the original `webupg`; the harmless command output was reflected
  as `FRIDAY_EX2800_UNCONFIGURED_RCE\n`.

Further control-flow tracing established that `name`, `key`, and `cmd` are all
intended to be query-string tokens. `UPGCGI_Main` locates `name=` and leaves
the libc `strtok` state positioned after it. When `name` equals `shell`, the
common dispatch calls `UPGCGI_WebShell`, which continues that same tokenizer
with `strtok(NULL, "&")`; it recognizes literal field names `key` and `cmd`,
requires the value `twmode`, formats the command as `%s 2>&1`, and calls
`popen`.

Breakpoint tracing resolved the final parser constraint. Immediately before
dispatch, `UPGCGI_Main` initializes libc's tokenizer with
`strtok(full_query, "&")` and discards that first token. It also compares the
entire suffix following `name=` with `shell`, requiring `name=shell` to be the
terminal field. `UPGCGI_WebShell` then consumes the second and later tokens.
The working field order is:

```
x=1&key=twmode&cmd=<command>&name=shell
```

The firmware URL decoder does not translate `+` to a space, and `mini_httpd`
rejects `%20` in this request target. The harmless proof therefore uses the
shell's standard `${IFS}` separator:

```
cmd=echo${IFS}FRIDAY_EX2800_UNCONFIGURED_RCE
```

The full isolated sequence produced:

```
setup_trigger_status=200 upgUnauth_created=true
response_body=b'FRIDAY_EX2800_UNCONFIGURED_RCE\n'
webshell_status=200
upgUnauth_consumed=true
harmless_command_executed=true
command_output_reflected=true
unauthenticated_rce_reproduced=true
```

This is an end-to-end emulation confirmation with the original `webproc`,
`mini_httpd`, and `webupg`. Emulation compatibility remains limited to the
hardware-init changes in `logic.emu`, its MTD ioctl shim, and the read-only
`/proc/llconfig/model` fixture. Physical-device confirmation and vendor/CNA
duplicate checking are still required before claiming a new zero-day.

Validator:

- `scripts/ex2800_unconfigured_rce_probe.py`
- `scripts/ex2800_local_probe.sh`

Both scripts pass `python3 -m py_compile` / `bash -n`.

## Other tested leads

### `/start_telnet`

Unauthenticated GET `/start_telnet` reproducibly installs a root telnetd inetd
rule, creates the enable marker, and restarts inetd. This is a confirmed
unauthenticated security-boundary change.

It is not currently confirmed as unauthenticated RCE:

- The firmware contains a fixed `root` / `root` credential.
- The selected root account entry points to `/bin/bash`.
- `/bin/bash` is absent from the firmware.
- A UID 0 interactive session was obtained only after adding a compatibility
  wrapper to the disposable lab, so that result is not faithful to the shipping
  image.

### Resolver command sink

`tbsResolveIpByName` reaches a genuine shell-command construction sink, but no
network-facing caller was identified. Rejected as remotely exploitable on the
available evidence.

### HTTP connection exhaustion

Holding approximately 16 incomplete HTTP connections temporarily prevented new
requests. Service recovered after the connections were released. This is
transient resource starvation, not a confirmed persistent DoS.

### Long request path / CGI failures

Some emulated CGI requests crashed child processes, but the parent HTTP service
remained alive and continued accepting requests. No persistent DoS was
reproduced.

## Confidence and next validation gate

- Direct command sink: high confidence (L4 static data flow).
- One-shot auth bypass in `webupg`: high confidence (L4 static control flow).
- Setup CGI marker creation: L5 confirmed over isolated loopback with an invalid
  dummy session cookie.
- End-to-end unauthenticated RCE: L5 confirmed in network-isolated firmware
  emulation, including reflected output from a harmless root shell command.
- Persistent unauthenticated DoS: not confirmed.
- Zero-day novelty: supported by the dated public-record review; classified as
  apparent because confidential duplicates cannot be excluded.

Physical-device confirmation would strengthen affected-product applicability
but is not necessary to describe the current result as emulation-confirmed
unauthenticated RCE. Public zero-day claims should still disclose the emulation
fixtures and avoid asserting novelty until duplicate research is complete.
