# Fifteen-router zero-day hunting campaign

Static findings are review leads, not confirmed vulnerabilities. Testing is limited to archived firmware and isolated emulators.

| Product | Version | Exact SHA-256 | Rootfs | HTTP leads | Impactful unauth HTTP | High-risk services |
|---|---|---|---:|---:|---:|---:|
| ASUS ZenWiFi BD4 | 3.0.0.6.102_58362 | `ecb07c94a5e8d3751ac5966573d13483b96a42a17168517684270b96429f4f7c` | yes | 0 | 0 | 200 |
| ASUS ZenWiFi BD5 | 3.0.0.6.102_58362 | `2017328dfc5bccce0422f9e22176490a101dd6d18625368215a8a50771edb2d3` | yes | 0 | 0 | 200 |
| ASUS ZenWiFi BE5000 | 3.0.0.6.102_58362 | `1f49ec85a429d63622e6a21bebd2149e946310da5cef2e15a2be2181c4061292` | yes | 0 | 0 | 200 |
| ASUS 4G-BE58 | 3.0.0.6.102_58741 | `5e2530465f11026c0739d7d88a3e7f8fb3a1b42d83a31ca3b9d450209c255906` | yes | 0 | 0 | 200 |
| ASUS RT-BE96U | 3.0.0.6.102_39262 | `1983ce9123ea5823006585233ad3f7c6966c4037d8202cc762656674537a4212` | yes | 0 | 0 | 200 |
| ASUS ROG Rapture GT-BE98 Pro | 3.0.0.6.102_39262 | `e9c3bdc196cdc00528be40fd92de066793dfada1b181ba01b142a5319a011eaf` | yes | 0 | 0 | 200 |
| ASUS ZenWiFi BQ16 Pro | 3.0.0.6.102_39256 | `ed0ce0716d166f1030e10b1ca1b36bf8dd2f5049d4c6484facb85218bbefc771` | yes | 0 | 0 | 200 |
| TP-Link Archer AX73 | V2.6_1.3.1 Build 20260430 | `bd8fcd7600e20b0c898edf1abf347716e7601b0dfb2cf8500ba99e1b2790b40b` | no | 0 | 0 | 0 |
| TP-Link Archer BE550 | V2.6_1.3.1 Build 20260403 | `a6106666c612851736f9574d0e8c810f78c1e1834ca9b4601d02814426c6bf6a` | no | 0 | 0 | 0 |
| TP-Link Archer BE800 | V1.6_1.4.1 Build 20260401 | `ef2885965a529ea719d44a55392ae8dd4811408e48165850343f74644824e7b5` | no | 0 | 0 | 0 |
| TP-Link Deco BE85 | V2.6_1.2.1 Build 20250731 | `36d4c17759c8be8d64e344d7b02161d3353b786b91157271f1475a030d5cd371` | no | 0 | 0 | 0 |
| R7000 | 1.0.12.216 | `b405d2c73809986ed32b412af0ba28daa195bca9f80f582c8c3b35e5d2545772` | yes | 0 | 0 | 145 |
| XR1000 | 1.0.2.86 | `7b082abc417e88981de960fa39af738996e5ca1cb2b3d83ad438b6ee6cdd21ec` | no | 0 | 0 | 0 |
| GL.iNet GL-BE9300 Flint 3 | 4.9.0 | `edf306a312c85c449a22d5badd791cc2bb5e530b2ad47ce2b710562554b9dfb8` | yes | 0 | 0 | 143 |
| GL.iNet GL-MT6000 Flint 2 | 4.9.0 | `6e8e6610f944996bb0c119fe95b5610c7091f14c3234739f68d3a5e73c0c60ce` | yes | 0 | 0 | 151 |

## Promotion queue

- **ASUS ZenWiFi BD4**: 0 impactful unauthenticated HTTP leads, 200 high-risk service leads; top non-HTTP service `cloud` (auth `device`, exposure `outbound`).
- **ASUS ZenWiFi BD5**: 0 impactful unauthenticated HTTP leads, 200 high-risk service leads; top non-HTTP service `cloud` (auth `device`, exposure `outbound`).
- **ASUS ZenWiFi BE5000**: 0 impactful unauthenticated HTTP leads, 200 high-risk service leads; top non-HTTP service `cloud` (auth `device`, exposure `outbound`).
- **ASUS 4G-BE58**: 0 impactful unauthenticated HTTP leads, 200 high-risk service leads; top non-HTTP service `cloud` (auth `device`, exposure `outbound`).
- **ASUS RT-BE96U**: 0 impactful unauthenticated HTTP leads, 200 high-risk service leads; top non-HTTP service `cloud` (auth `device`, exposure `outbound`).
- **ASUS ROG Rapture GT-BE98 Pro**: 0 impactful unauthenticated HTTP leads, 200 high-risk service leads; top non-HTTP service `cloud` (auth `device`, exposure `outbound`).
- **ASUS ZenWiFi BQ16 Pro**: 0 impactful unauthenticated HTTP leads, 200 high-risk service leads; top non-HTTP service `cloud` (auth `device`, exposure `outbound`).
- **GL.iNet GL-MT6000 Flint 2**: 0 impactful unauthenticated HTTP leads, 151 high-risk service leads; top non-HTTP service `cloud` (auth `device`, exposure `outbound`).
- **R7000**: 0 impactful unauthenticated HTTP leads, 145 high-risk service leads; top non-HTTP service `cloud` (auth `device`, exposure `outbound`).
- **GL.iNet GL-BE9300 Flint 3**: 0 impactful unauthenticated HTTP leads, 143 high-risk service leads; top non-HTTP service `cloud` (auth `device`, exposure `outbound`).
- **TP-Link Archer AX73**: 0 impactful unauthenticated HTTP leads, 0 high-risk service leads; no-usable-rootfs.
- **TP-Link Archer BE550**: 0 impactful unauthenticated HTTP leads, 0 high-risk service leads; no-usable-rootfs.
- **TP-Link Archer BE800**: 0 impactful unauthenticated HTTP leads, 0 high-risk service leads; no-usable-rootfs.
- **TP-Link Deco BE85**: 0 impactful unauthenticated HTTP leads, 0 high-risk service leads; no-usable-rootfs.
- **XR1000**: 0 impactful unauthenticated HTTP leads, 0 high-risk service leads; no-usable-rootfs.

## Current conclusion

No confirmed zero-day was produced by this first pass. A candidate requires route/service-specific control-flow evidence, a proven unauthenticated boundary, and repeatable impact in an isolated emulator before promotion.

Five images still lack a usable root filesystem because their signed, nested, or damaged containers were not decoded: Archer AX73, Archer BE550, Archer BE800, Deco BE85, and XR1000.

## Historical-vulnerability correlation (2026-07-15 follow-up)

Primary vendor advisories show a repeated cross-vendor pattern:

- ASUS 3.0.0.6_102 models (all seven ASUS targets): prioritize AiCloud authentication control and command-building paths. ASUS associates this firmware family with CVE-2025-2492 (improper authentication control) and CVE-2024-12912/CVE-2024-13062 (authenticated injection/execution).
- Archer AX73: prioritize VPN server configuration, but treat the exact `1.3.1 Build 20260430` image as the fixed boundary for CVE-2026-22226. TP-Link lists only versions earlier than this build as affected.
- Archer BE550, BE800, and Deco BE85: prioritize sibling web/VPN/cloud/configuration-import modules. Recent TP-Link router advisories repeatedly cluster command injection in those modules, but no exact-model applicability was established from the available advisory data.
- XR1000: prioritize traffic-update validation, local authentication boundaries, and legacy command builders. NETGEAR lists `1.0.2.86` as the fix for CVE-2026-9213 and separately documents historical pre-authentication command injection/buffer-overflow families and post-authentication command injection on XR1000.
- R7000: prioritize web dispatcher authentication exceptions and configuration-to-shell paths. Historical R7000 issues include unauthenticated and authenticated command injection plus stack-based overflow families.
- Flint 2 and Flint 3: prioritize GL.iNet RPC/API permission checks, package/plugin installation, backup restore, and vendor feeds layered above OpenWrt. No exact current-model CVE applicability was established in this pass.

### R7000 strongest lead and dynamic gate

The exact ARM `usr/sbin/httpd` contains an authentication-exception function at `0x10c14` that uses substring matching for `unauth.cgi`, `passwordrecovered.cgi`, `multi_login.cgi`, and several pages. Follow-up data-flow review corrected the original query-string hypothesis: at `0x12cd8` the caller passes `r4`, and `r4` was assigned at `0x11480` from the result of a case-insensitive `User-Agent:` header lookup. An attacker-controlled User-Agent containing an allowlisted filename can therefore select the exception branch. This is a concrete authentication-boundary defect in the exact binary, but downstream unauthorized access or impact is not yet dynamically proven.

The first rehost used `blank_state=1`, so it was not a valid configured-router authentication test. Restoring `blank_state=0` initially exposed stale System V IPC state: `shmat()` returned `-1` and was dereferenced at `main+0x1f8` (`0x19aac`), while a later launch failed with `Semaphore Create Failed`. The blocker was resolved by removing the disposable container's orphaned shared-memory segments and semaphore plus `/tmp/shm_id`. On the clean launch, the unchanged firmware allocated shared-memory ID `3`, semaphore ID `1`, completed initialization, and bound port 80. Missing physical MTD devices produced non-fatal warnings and were not the startup blocker.

The configured, logged-out differential is negative. A normal User-Agent and `User-Agent: FRIDAY unauth.cgi canary` both returned byte-identical HTTP 401 responses for `PWD_password.htm` (274-byte bodies; SHA-256 `7410f3db8ad265446b764150a872e00d8a36060f6cec361547a3eabc96b1af76`). Repeating the pair after one deliberately invalid login produced the same result. Thus the static User-Agent/allowlist data flow does not currently demonstrate an authentication bypass. The emulator blocker is resolved, but this candidate is not promoted to an exploit or zero-day.

Evidence: `router-agent-results/20260709T145527Z-R7000-V1.0.12.216.zip/artifacts/exploit-proof-results.json`.

Primary references:

- https://www.tp-link.com/us/support/faq/4935/
- https://kb.netgear.com/000070811/June-2026-NETGEAR-Security-Advisory
- https://kb.netgear.com/000066029/Security-Advisory-for-Post-Authentication-Command-Injection-on-the-XR1000-PSV-2023-0152
- https://kb.netgear.com/000064523/Security-Advisory-for-Pre-Authentication-Command-Injection-on-Some-Routers-Extenders-and-WiFi-Systems-PSV-2020-0562
- https://kb.netgear.com/000064777/Security-Advisory-for-Pre-Authentication-Buffer-Overflow-on-Some-Routers-Extenders-and-WiFi-Systems-PSV-2020-0445
- https://www.asus.com/security-advisory/
- https://github.com/gl-inet/CVE-issues
