# RAX54S 1.0.17.144: pre-authentication UPnP SOAP body overflow candidate

## Superseded by dynamic validation (2026-07-24)

This candidate was not confirmed and must not be treated as an
unauthenticated-UPnP finding. Testing the exact firmware daemon showed that
`/Public_UPNP_C3` serves WANIPConnection, while the handler containing the
unchecked copy belongs to the proprietary `httpd` path at `/soap/server_sa/`.
`DeviceInfo:1#GetInfo` requests with 0 through 1,024 bytes of inert padding
did not terminate either tested service. The public `upnpd` path returned SOAP
faults and passed WANIPConnection liveness controls. After the proprietary
`httpd` path was brought to a stable full-system state, `/soap/server_sa/`
returned HTTP 200 for every tested size and passed a fresh HTTPS control after
every case.

The static unsafe copy remains relevant to future `httpd` analysis, but its
unauthenticated reachability and impact are unproven. See
`RAX54S-V1.0.17.144-unauth-rce-dos-investigation.md` for the corrected
disposition and dynamic evidence.

## Disposition

- Product: Netgear RAX54S
- Firmware: `1.0.17.144`
- Firmware SHA-256: `12d0be80c7dfee7ffd6d6257f37afde4ddbef6951ee3e6b35674eca529f539a3`
- Component: `/usr/sbin/upnpd`
- Binary MD5 (Ghidra import): `3c148cf0f4d2255b6171994fd91a9bc6`
- Exposure: LAN UPnP HTTP/SOAP
- Authentication: unauthenticated reachability not established
- Candidate impact: daemon crash (DoS); adjacent-memory corruption and RCE require dynamic proof
- Evidence level: L3 static source-to-sink trace
- Status: superseded/refuted as a public-UPnP candidate; not a confirmed zero-day

## Why this target was selected

The seventy-four-router campaign marks RAX54S as fully decompiled: all three eligible
ELFs succeeded. Its `upnpd` decompile covers all 279 discovered functions and identifies
command-execution and unsafe-memory primitives. A focused audit was therefore run over
the public SOAP endpoint, action names, and authentication markers.

## Static trace

The request handler is `FUN_000599dc` at `0x000599dc`.

1. `param_1` is the received HTTP/SOAP request. The handler locates `SOAPAction:` with
   `strcasestr`.
2. The authentication branch contains explicit comparisons for only three public
   operations:
   - `urn:NETGEAR-ROUTER:service:ParentalControl:1#Authenticate`
   - `urn:NETGEAR-ROUTER:service:DeviceConfig:1#SOAPLogin`
   - `urn:NETGEAR-ROUTER:service:DeviceInfo:1#GetInfo`
3. Other actions enter the session/cookie validation path. This rejects the earlier
   unauthenticated `SetFirmware`, firmware-update, NTP, and OOKLA command-injection
   hypotheses unless a separate authentication bypass is found.
4. After the public-action decision, the handler obtains a global destination through
   `*(iVar39 + DAT_0005a954)` and clears exactly 100 bytes:

   ```c
   pcVar6 = *(char **)(iVar39 + DAT_0005a954);
   memset(pcVar6, 0, 100);
   ```

5. It finds body/action delimiters in the attacker-controlled request and derives a
   copy length from their pointer distance:

   ```c
   pcVar4 = strcasestr(param_1, BODY_START);
   pcVar8 = strcasestr(param_1, action_string);
   sVar5 = strlen(action_string);
   ...
   memcpy(pcVar6 + sVar9 + 0x12,
          pcVar4,
          (size_t)(pcVar8 + (sVar5 - (int)pcVar4)));
   ```

6. No comparison between that length and the 100-byte destination is visible before
   the `memcpy`. A syntactically matched `GetInfo` request with expanded content
   between the body start and action delimiter should therefore write beyond the
   cleared destination.

The unsafe copy is in the same function and request path as the authentication
exception, so this is stronger than a string or sink-only heuristic. PIE, stack
canaries, and the destination's actual placement may change exploitability but do not
remove the apparent out-of-bounds write.

## Safe validation plan

Validate only in an isolated RAX54S emulator or owned test unit:

1. Send a normal unauthenticated `DeviceInfo:1#GetInfo` request and require a successful
   response as the control.
2. Repeat with inert `A` padding before the matched closing action delimiter, starting
   at 128 bytes and increasing only to 256, 512, and 1024 bytes.
3. After every request, repeat the control request. Stop on the first service failure.
4. Capture the exact request, response, daemon log, core, and post-request liveness.
5. Reboot/reset the lab and reproduce the smallest crashing length three times.
6. Inspect the core to establish the overwritten object, program counter/control-data
   influence, and whether the result is only a daemon DoS.

Do not use shell payloads during this phase. A core showing an overwrite at the
identified `memcpy`, plus reproducible loss of `upnpd`, would raise this to confirmed
DoS. RCE should not be claimed without demonstrated control-flow influence under the
firmware's actual mitigations.

## Evidence

- Focused Ghidra output:
  `known_firmware/reports/RAX54S/decompile/upnpd-public-soap-audit.c`
- Complete candidate decompile:
  `known_firmware/reports/RAX54S/decompile/upnpd-candidate-functions.c`
- Coverage receipt:
  `known_firmware/reports/RAX54S/decompile/upnpd-receipt.json`
- Campaign result:
  `router-agent-results/20260722T235859Z-seventy-four-router-hunt/results/049-12d0be80c7df.json`

## Confidence and remaining uncertainty

Confidence is high that the handler contains a length-unchecked copy sourced from the
HTTP request. Confidence is moderate that the exact `GetInfo` variant reaches it
without a session because the authentication comparisons and service-index checks are
recovered from stripped, position-independent code. Dynamic validation is required to
confirm reachability, the first crashing length, and impact.
