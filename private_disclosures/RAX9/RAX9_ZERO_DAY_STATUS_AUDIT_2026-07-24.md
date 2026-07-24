# RAX9 pre-authentication RCE: zero-day status audit

Date: 2026-07-24 UTC

## Determination

**Not a current zero-day.**

The unauthenticated root command-injection chain is confirmed in RAX9
V1.0.3.32, but the latest available family firmware, V1.0.9.44, contains an
exact and effective fix. It is best described as a confirmed vulnerability
in an older firmware release, or potentially a silently fixed/previously
undocumented vulnerability. It must not be represented as an unpatched
zero-day.

## Evidence

1. V1.0.3.32 full-system emulation reaches the production password-reset CGI
   without authentication and creates a fixed marker as UID/GID 0.
2. A historical diff shows V1.0.9.44 added a three-entry dispatcher allowlist
   (`checkSN`, `checkAnswer`, `setPassword2`) that rejects `accessCtrlDev`.
3. The dangerous handler and `/bin/sh -c` helper are byte-identical between
   V1.0.3.32 and V1.0.9.44, isolating the relevant security patch.
4. The identical request against full-system V1.0.9.44 logs the allowlist
   rejection and does not create the marker.
5. The tested V1.0.9.44 image SHA-256 exactly matches the image in NETGEAR's
   official RAX9 download package.
6. NETGEAR's V1.0.9.44 release notes say that the release addresses security
   vulnerabilities, but do not identify this root cause.

## Version boundary

- Confirmed vulnerable: V1.0.3.32
- Intermediate V1.0.7.42: unresolved; an official binary was not obtainable
  from the public download URLs or indexed support material.
- Confirmed fixed: V1.0.9.44

Therefore, the first fixed release is either V1.0.7.42 or V1.0.9.44. This
uncertainty does not alter the zero-day determination because current
V1.0.9.44 is demonstrably fixed.

## Public prior-art audit

Searches covered the exact endpoint, Lua module/function names, allowlist
text, model/version combinations, CVE/NVD entries, NETGEAR security
advisories, and general web results. No public source describing this exact
`reset_pwd.plua` -> arbitrary `webPostHandler` -> `accessCtrlDev` root cause
was found. Older NETGEAR pre-authentication command-injection advisories
examined apply to other models/codebases and do not establish this exact
issue as prior art.

Absence from public search is not proof that NETGEAR has no private duplicate
or internal PSV record. Because vendor duplicate checking was intentionally
excluded, historical novelty remains **unresolved**, even though current
zero-day status is negative.

## Physical-device check

Read-only route, interface, and neighbor discovery found no identifiable
physical RAX9/R6700AXv3 on an attached private LAN. The visible default
gateway is on a public infrastructure subnet and was not probed or tested.
No physical-device claim is made.

## Classification

- Vulnerability: confirmed
- Unauthenticated: confirmed
- Root RCE on V1.0.3.32: confirmed
- Current firmware affected: no
- Exact public disclosure found: no
- Vendor-private prior knowledge: unknown (not queried)
- Current zero-day: **no**
- Appropriate label: **confirmed old-firmware pre-authentication root RCE;
  apparently silently fixed by V1.0.9.44**
