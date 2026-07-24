# 74-router unauthenticated RCE/DoS campaign

Date: 2026-07-24

## Outcome

The current campaign confirms one unauthenticated root-RCE chain and three
distinct unauthenticated service-denial conditions in firmware images from
the 74-router set.

| Product | Firmware | Impact | Evidence level |
| --- | --- | --- | --- |
| NETGEAR RAX9 | 1.0.3.32 | Pre-auth password-reset dispatcher command injection; root RCE | Full-system genuine-component emulation |
| NETGEAR RAX9 | 1.0.3.32 | Malformed MiniUPnPd `SOAPAction` terminates the daemon | Genuine-binary emulation |
| NETGEAR RAX29 | 1.0.14.108 | Valid no-port UPnP `SUBSCRIBE` callback causes a null dereference | Full-system genuine-component emulation |
| NETGEAR RAX30 | 1.0.14.108 | Same no-port UPnP event-callback defect in the identical daemon | Full-system genuine-component emulation |

The RAX29 and RAX30 entries are one shared vulnerability affecting two
products. The confirmed technical total is therefore:

- one unauthenticated root RCE;
- two distinct unauthenticated service-DoS vulnerabilities;
- three affected products in the 74-image inventory.

Physical-hardware confirmation and vendor/CNA duplicate determinations remain
pending. None of these results establishes WAN reachability or a whole-router
outage.

## Exhaustive evidence pass

The later exhaustive campaign inventory contains 74 firmware images, 9,095
unique ELF binaries, and 9,832 receipts. Re-ranking those receipts produced
13,283 function-level heuristic leads. This number is not a vulnerability
count: large functions frequently contain unrelated network-input, command,
and memory APIs.

The ranked output is preserved at:

`router-agent-results/20260722T235859Z-seventy-four-router-exhaustive-decompile/preauth-ranked-2026-07-24.json`

## High-scoring families resolved

### ASUS/NETGEAR `wl_server_socket`

The component contains a real unauthenticated remote shell and executes
received commands when launched. Component execution is dynamically
confirmed. Stock startup activation has not been found, so binary presence is
not promoted to a product-level vulnerability. The same activation barrier
applies to the copies ranked across multiple ASUS and NETGEAR images.

### OpenWrt and GL.iNet `cgi-io`

The execution calls launch fixed BusyBox helpers. Existing genuine-component
tests found session/ACL enforcement and no unauthenticated arbitrary command
or file-operation path. The scorer's `getenv` plus `exec` correlation is not a
command-injection dataflow.

### RAX28/RAX29 `debug.cgi`

Focused decompilation was added at
`known_firmware/reports/RAX28-debug-cgi-xrefs.c`.

The CGI parses request environment and query values, but its field extraction
uses explicit 32- or 64-byte limits. Its `popen` and `system` calls use fixed
commands or formats selected from enumerated state. No query-string-to-shell
command flow was found. Web-server authentication placement should still be
recorded if this diagnostic surface receives future testing, but the current
evidence does not support RCE.

### DHCP, DNS, SSH, and large HTTP functions

`fgets`, `read`, `system`, and unsafe-copy imports coexisting in a daemon are
insufficient. Many high scores came from configuration-file parsing, child
process setup, or authenticated handlers rather than network-packet dataflow.
These require protocol-specific call-chain and startup evidence before
dynamic testing.

## Product-specific findings already excluded

- ASUS RP-AX56 51891: live DNS/DHCPv4, MiniUPnPd, `infosvr`, and `cfg_server`
  matrices found no new crash. Its known dnsmasq CVE-2022-0934 path requires
  DHCPv6, while stock defaults set `ipv6_service=disabled`.
- GT-BE98 Pro `wl_server_socket`: conditional component RCE only; no stock
  activation.
- Current OpenWrt `cgi-io` images: ACL-gated, fixed-helper behavior.
- RAX42v2 IPP: emulator-only termination did not transfer to the stock service
  environment and is not a product-level confirmation.

## Next distinct priorities

1. TP-Link Archer C54 monolithic image: recover its native service map and
   packet dispatchers because the first campaign classified it as
   `no_eligible_elf`.
2. ASUS GS-BE7200/GS-BE7200X `dhcpfwd`, `lld2c`, and `dnsqd`: prove stock
   startup and packet-input call chains before emulation.
3. RAX28/RAX29 diagnostic HTTP routing: confirm whether `debug.cgi` is
   authenticated and run only bounded parser tests if it is pre-auth.
4. Resolve RAX54S/RAX54Sv2 family-specific UPnP candidates using corrected
   production startup profiles.

## Classification standard

A result is confirmed only when:

1. the stock service is shown active and reachable;
2. the entry point requires no authentication;
3. attacker-controlled input reaches the fault or execution sink; and
4. a genuine component produces an execution marker, fatal signal, or
   persistent loss of service with a clean control comparison.

Static sink matches, component-only backdoors without activation, and
emulator-specific failures remain leads rather than vulnerabilities.
