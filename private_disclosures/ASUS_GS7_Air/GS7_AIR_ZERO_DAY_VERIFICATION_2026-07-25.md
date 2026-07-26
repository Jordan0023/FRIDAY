# ASUS GS7 Air zero-day verification record

Date: 2026-07-25 UTC

## Disposition

- Vulnerability reproduced: yes
- Authentication required: no on LAN
- Impact: transient management-plane denial of service
- Current GS7 Air production firmware affected: yes
- Repeated reproduction: yes
- Related production model affected: yes, GS7 Bear Brick
- Matching public disclosure found: no
- ASUS contacted: no, per operator instruction
- Defensible label: publicly undisclosed zero-day candidate
- Definitive product zero-day claim: withheld pending physical-hardware
  reproduction or independent confirmation

## Current-production verification

A read-only query to ASUS's live global support API on 2026-07-25 returned
exactly one GS7 Air production release:

```text
Product       ASUS ROG Strix GS7 Air
PDID          36527
Version       3.0.0.6.102_58833
Release date  2026/02/04
Package       FW_GS7_AIR_300610258833.zip
```

This is the exact package used in the investigation:

```text
SHA-256 a0ea5c3a242b006a91ff8d2d0a3e766798c249a0832ad5abe61461dae472af49
```

Therefore the current production GS7 Air firmware is affected in full-system
emulation.

## Repetition

The GS7 Air chain was reproduced in five bounded LAN runs and one conditional
WAN run. The three preserved repeat runs were materially identical:

| Run | Burst timeouts | First independent control | Threads | Ping execs | Recovery |
| --- | ---: | ---: | ---: | ---: | --- |
| repeat-1 | 31/40 | timeout at 15.015 s | 42 | 41 | yes |
| repeat-2 | 31/40 | timeout at 15.015 s | 42 | 41 | yes |
| repeat-3 | 31/40 | timeout at 15.015 s | 42 | 41 | yes |

Every run confirmed unauthenticated handler continuation with two HTTP status
lines and `{"successful":"0"}`. `httpd` and the genuine net-tool daemon
remained alive, attributing the transient outage to worker/thread and ping
child-process accumulation rather than a crash.

Artifacts:

- `router-agent-results/gs7-air-triage/netool-lan-dos-evidence-2026-07-24-repeat-1.txt`
- `router-agent-results/gs7-air-triage/netool-lan-dos-evidence-2026-07-24-repeat-2.txt`
- `router-agent-results/gs7-air-triage/netool-lan-dos-evidence-2026-07-24-repeat-3.txt`
- `router-agent-results/gs7-air-triage/netool-wan-dos-evidence-2026-07-24.txt`

## Cross-model reproduction

The same bounded test reproduced on the related ASUS ROG Strix GS7 Bear Brick
using different `httpd` and `rc` binaries:

```text
Firmware       3.0.0.6.102_58406
Burst timeouts 31/40
First control  timeout at 15.016 seconds
Threads        42
Ping execs     41
Recovery       yes
```

ASUS's live support API lists `_58406`, released 2026/05/26, as the newest
Bear Brick production firmware. This establishes a second current production
firmware/model in emulation; it is not a substitute for two physical routers.

Artifact:

- `router-agent-results/gs7-triage/netool-lan-dos-evidence-2026-07-24-cross-model.txt`

GS7 Pro was also attempted. It is a 32-bit ARM/Broadcom image, while the
existing full-system lab and NVRAM compatibility library are AArch64. Its
`httpd` reached bind but exited because the cross-architecture lab did not
provide the expected runtime layout. That attempt is not counted as positive
or negative product evidence.

## Public prior-art search

Search date: 2026-07-25 UTC.

Searched terms and identifiers included:

- `ASUS GS7 Air vulnerability CVE netool.cgi DoS`
- `ASUSWRT netool.cgi unauthenticated denial of service`
- `"netool.cgi" ASUS vulnerability`
- `"netool.cgi" router DoS`
- `"/var/run/netool_socket" vulnerability`
- `ASUS router unauthenticated worker exhaustion ping diagnostic netool`
- NVD/CVE, GitHub Advisory Database, ASUS Product Security Advisory, Zero Day
  Initiative, and general indexed-web results

No result described the authentication-dispatch continuation plus
`netool.cgi` worker/process-exhaustion mechanism.

Relevant non-matches:

- CVE-2021-3229: continuous login-error DoS on RT-AX3000; different endpoint,
  model, and mechanism.
- CVE-2025-15101: authenticated administrator command injection; different
  privilege requirement and impact.
- CVE-2026-11851: authenticated SQL injection and disclosure.
- CVE-2026-13385: MITM update integrity/certificate validation leading to
  command execution.
- 2026 Broadcom Wi-Fi parser DoS reporting: malformed 802.11 traffic and
  device/network crash; different layer and mechanism.

The absence of indexed public prior art does not exclude an unknown private,
embargoed, or unindexed duplicate. Because ASUS was not contacted, vendor
knowledge and internal duplication cannot be determined.

## Conclusion

The evidence supports a previously publicly undocumented vulnerability in the
latest production firmware of two related products, reproducible across
multiple full-system runs. It is reasonable to track it internally as a
**zero-day candidate**.

Calling it a definitively confirmed product zero-day would overstate the
evidence because:

1. both affected products were validated in emulation rather than on physical
   retail hardware;
2. no independent third party has reproduced it; and
3. without vendor coordination, an unknown private duplicate cannot be ruled
   out.

