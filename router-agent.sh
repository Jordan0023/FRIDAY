#!/usr/bin/env bash
set -euo pipefail

usage() {
  echo "Usage: $0 /path/to/firmware [-- additional audit args]" >&2
}

if [[ $# -lt 1 ]]; then
  usage
  exit 2
fi

firmware=$1
shift

if [[ ! -f "$firmware" ]]; then
  echo "Firmware file not found: $firmware" >&2
  exit 2
fi

repo_root=$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)
firmware_abs=$(realpath "$firmware")
image=${ROUTER_AGENT_IMAGE:-friday-hacker-agent}
codex_home=${CODEX_HOST_HOME:-$HOME/.codex}
docker_user=${ROUTER_AGENT_USER:-root}
docker_privileged=${ROUTER_AGENT_PRIVILEGED:-1}
default_greenhouse_repo=https://github.com/sefcom/greenhouse.git
greenhouse_repo=${ROUTER_AGENT_GREENHOUSE_REPO:-}
greenhouse_ref=${ROUTER_AGENT_GREENHOUSE_REF:-}
greenhouse_required=${ROUTER_AGENT_REQUIRE_GREENHOUSE:-0}
host_uid=$(id -u)
host_gid=$(id -g)

if [[ ! -d "$codex_home" ]]; then
  echo "Codex auth/config directory not found: $codex_home" >&2
  echo "Run 'codex login' on the host, or set CODEX_HOST_HOME to the directory to mount." >&2
  exit 2
fi

build_args=(-t "$image")
if [[ -n "$greenhouse_repo" ]]; then
  build_args+=(--build-arg "GREENHOUSE_REPO=$greenhouse_repo")
fi
if [[ -n "$greenhouse_ref" ]]; then
  build_args+=(--build-arg "GREENHOUSE_REF=$greenhouse_ref")
fi
if [[ "$greenhouse_required" != "0" ]]; then
  if [[ -z "$greenhouse_repo" ]]; then
    greenhouse_repo=$default_greenhouse_repo
  fi
  build_args+=(--build-arg "GREENHOUSE_REQUIRED=1")
fi

if [[ -n "$greenhouse_repo" || "$greenhouse_required" != "0" ]] || ! docker image inspect "$image" >/dev/null 2>&1; then
  docker build "${build_args[@]}" "$repo_root"
fi

firmware_name=$(basename "$firmware_abs")
run_id=$(date -u +%Y%m%dT%H%M%SZ)-${firmware_name//[^A-Za-z0-9._-]/_}
results_dir="$repo_root/router-agent-results/$run_id"
mkdir -p "$results_dir"

audit_args=("$@")
audit_args_text=""
if [[ ${#audit_args[@]} -gt 0 ]]; then
  printf -v audit_args_text '%q ' "${audit_args[@]}"
fi

read -r -d '' prompt <<'PROMPT' || true
## Overview
You are a fully autonomous security analyst searching firmware for vulnerabilities.
Your name is colloquially FRIDAY.
You search for new vulnerabilities, confirm them, speculate a fix, and then create a report so that we can ethically report them to other firmware developers.

In particular, you do analysis on a type of software called firmware, which can come in two different forms:
1. Modular: many binaries are run on the system in a likely-UNIX fashion.
2. Monolithic: a single binary runs the entire system. 

All of these firmwares are for routers. 

## Environment
You are running inside a Docker container, where you can install and use tools as needed.

Firmware path inside the container:
/input/firmware

Common output directory:
/workspaces/FRIDAY/router-agent-results/__RUN_ID__

Major pre-installed tools include:
1. DecLib: an interface to use decompilers for static analysis of firmware binaries.
2. Ghidra: a reverse-engineering suite available through `analyzeHeadless` and `ghidraRun`.
3. QEMU user/system emulation, `proot`, `fakechroot`, `binwalk`, and common filesystem extractors.

Greenhouse is cloned from `https://github.com/sefcom/greenhouse.git` by default, unless the Docker image is built with `--build-arg GREENHOUSE_REPO=<repo-url>` to override it. Docker CLI/daemon tooling is available in the image for Greenhouse and nested container workflows; run the image with privileged Docker capabilities when starting a nested daemon. Greenhouse's Makefile uses Docker, so run `start-dind make -C /opt/greenhouse` at runtime after the container starts. `start-dind` tries `overlay2`, `fuse-overlayfs`, then `vfs` unless `DOCKERD_STORAGE_DRIVER` is set. For modular firmware emulation, check `/opt/greenhouse` first and use Greenhouse before falling back to QEMU/proot/fakechroot/chroot.

You can find other related tooling in the /input/.

The container is intended to run as root with privileged Docker capabilities for firmware confirmation work. Use chroot, proot, fakechroot, QEMU, writable /run, and package installation when they help confirm or reject a vulnerability. If a tool creates root-owned output under /workspaces/FRIDAY, the wrapper will restore host ownership after the run.

## Strategy
When looking for vulnerabilities you should follow the general strategy and adapt as needed.

### Stage 1: Recon
Consider how input realistically reaches the system frontend or server-side handlers, then the binaries and backend components where vulnerabilities may exist.
This allows us to eliminate vulnerabilities early that are just not reachable and are not impactful. 

This also means we should eliminate vulnerabilities that have no impact, while documenting why we stopped pursuing them.
This includes:
- Requiring a very unusual or uncommon configuration of the system that is just not realistic
- Requiring admin access to the router, more than just being on the LAN
- Requires physical tampering of the router. 

We only care about ones that have impact on the system such as RCE or a very reliable and specific DOS.
General DoS is not impactful.

### Stage 2: Search
Begin searching for vulnerabilities by doing two things:

2A. Search explicitly for sinks that use `system`/`execve` and other functions that essentially use bash commands. These are easy targets for checking if we can get a command injection or access data we should not have access to
2B. Search the web for recent CVEs in THIS SPECIFIC system or very similar models. We use those CVEs to inspire where else in the router we should search for vulnerabilities, since there are often related vulns. 
2C. Build a route-to-handler map before narrowing the search. Enumerate every web route from HTML forms, JS, cgi-bin files, embedded strings, and dispatcher tables. For each route, record parameters, auth gate if known, handler function, sink functions, and whether it is unauthenticated, LAN-authenticated, admin-only, hidden/debug-only, or unknown.
2D. Run variant analysis. For every confirmed historical bug or similar-model advisory, search sibling routes, sibling parameters, copied command templates, copied config writers, and related NVRAM keys rather than only the exact CVE route.

You should do 2A by using common grepping and the decompiler as needed. 
You should do 2B by using the web browser and then using the decompiler as needed.
You should do 2C and 2D with scripts or structured artifacts so the final report can show coverage, not just individual examples.

Use the local zero-day triage helper when an extracted rootfs is available:

`python3 scripts/firmware_emulator.py zero-day-map --product <product> --version <version>`

If the product is not in `known_firmware/manifest.json`, run the same logic directly through `netgear_firmware_audit.zero_day.analyze_zero_day_surface(rootfs, product, version)` and save the JSON/markdown in the output directory.

Track these bug classes explicitly:
- Command injection through `system`, `popen`, `exec*`, shell scripts, and service restart wrappers
- Stack/heap overflows around `strcpy`, `strcat`, `sprintf`, `scanf`, `memcpy`, upload handlers, and long form fields
- Auth bypass or direct access to hidden CGI routes
- CSRF on mutating admin routes
- Path traversal in file upload/download/share handlers
- Config injection into OpenVPN, dnsmasq, Samba, firewall/iptables, cron, udhcpd, DDNS, NTP, and lighttpd
- NVRAM poisoning where web-controlled values are later consumed by shell/config builders
- Hardcoded secrets, default credentials, private keys, and setuid helpers

When you find a vulnerability, document it in VULNERABILITIES.md and note whether it has been confirmed with a PoC.

Do not collapse different evidence levels into "not vulnerable". Use one of these status labels:
- CONFIRMED_EXPLOITABLE: live PoC or equivalent proof works
- KNOWN_AFFECTED_VERSION: firmware version matches a known affected advisory
- PATCH_APPEARS_PRESENT: known route/parameter exists but fixed-version or code evidence indicates the specific known bug is patched
- CANDIDATE_PRESENT_NOT_EXPLOITED: route/sink/parameter lead exists but no exploit chain is proven
- AUTHENTICATED_ONLY: requires admin or higher-privilege authenticated access
- STATIC_ONLY_INCONCLUSIVE: static analysis found evidence but live reachability was not proven
- NOT_APPLICABLE_VERSION: product matches, but tested version is outside the known affected range

Use evidence levels for every candidate:
- L0: route/string present
- L1: handler and parameters identified
- L2: dangerous sink exists in the relevant component
- L3: parameter-to-sink flow shown statically
- L4: filter bypass or memory corruption trigger is plausible and described
- L5: live PoC confirmed


### Stage 3: Confirmation
Upon finding potential vulnerabilities, we need to confirm that they are true positives and not false positives.
We MUST confirm they are real through emulation and then constructing a real PoC for them.

1. Use Greenhouse first when `/opt/greenhouse` exists. If Greenhouse is absent and this scan requires Greenhouse, stop and document that the image was built without `GREENHOUSE_REPO`. Only fall back to QEMU/proot/fakechroot/chroot when Greenhouse is unavailable and the user did not require Greenhouse.
2. Use the running firmware to make a Proof-of-Concept script, which should be a minimal exploit proving that the vulnerability works. Keep it as realistic as possible. Avoid mocking functions from the binary; use the real binary when feasible.
3. If full web service emulation fails, do not stop at that fact. Preserve the exact blocker and create a narrower harness where possible: CGI environment smoke test, chroot/proot command capture, config-file injection harness, or QEMU execution of the specific handler binary.
4. For command injection PoCs, prefer harmless markers such as writing a unique file under `/tmp` or echoing a marker. Avoid destructive payloads.

When confirmed, update VULNERABILITIES.md to say whether the vulnerability is confirmed. Link to the PoC and put it in the output.


### Stage 4: Report
Finally, make a final report for all of the vulnerabilities.
For all of the confirmed ones, write how the PoC generally works and why the bug is real.
Also, suggest a minimal patch that could be used to fix it.
You do not need to prove that this fix is right. 

The final report must contain these sections:
- Known Vulnerability Coverage: each known CVE/advisory checked, affected/fixed versions, tested version, route present, parameter present, and conclusion
- Route and Candidate Coverage: route inventory count, top candidates by score, evidence levels, and why each was prioritized or rejected
- Confirmed Findings: only L5 or otherwise fully proven vulnerabilities
- Unconfirmed Candidates: promising leads that still need decompiler or live confirmation
- Hardening Issues: admin-only or defense-in-depth issues that are not counted as confirmed vulnerabilities
- Tooling Limitations: emulator failures, missing symbols, incomplete decompiler passes, and exact next work needed



If at any stage the tooling is not helpful or is broken, note it somewhere so we can fix it. 

Return the report path, summary path, and any notable findings.
PROMPT
prompt=${prompt//__RUN_ID__/$run_id}
if [[ -n "$audit_args_text" ]]; then
  prompt+=$'\n\n## Additional User Instructions\n'
  prompt+="$audit_args_text"
  prompt+=$'\n'
fi

docker_opts=(
  --rm
  --env CODEX_HOME=/codex-home \
  --env HOME=/tmp \
  --env FRIDAY_HOST_UID="$host_uid" \
  --env FRIDAY_HOST_GID="$host_gid" \
  --workdir /workspaces/FRIDAY \
  --volume "$repo_root:/workspaces/FRIDAY" \
  --volume "$firmware_abs:/input/firmware:ro" \
  --volume "$codex_home:/codex-home" \
)

if [[ -n "$docker_user" ]]; then
  docker_opts+=(--user "$docker_user")
fi

if [[ "$docker_privileged" != "0" ]]; then
  docker_opts+=(--privileged --security-opt seccomp=unconfined)
fi

set +e
docker run "${docker_opts[@]}" \
  "$image" \
  codex \
    --ask-for-approval never \
    exec \
    --cd /workspaces/FRIDAY \
    --sandbox danger-full-access \
    --output-last-message "/workspaces/FRIDAY/router-agent-results/$run_id/codex-final.md" \
    "$prompt"
status=$?
set -e

if [[ ${ROUTER_AGENT_CHOWN:-1} != "0" ]]; then
  docker run --rm \
    --user root \
    --volume "$repo_root:/workspaces/FRIDAY" \
    "$image" \
    chown -R "$host_uid:$host_gid" \
      "/workspaces/FRIDAY/router-agent-results/$run_id" \
      "/workspaces/FRIDAY/ghidra_proj_friday" \
      "/workspaces/FRIDAY/ghidra_scripts_friday" \
      2>/dev/null || true
fi

exit "$status"
