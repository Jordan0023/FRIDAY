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

if [[ ! -d "$codex_home" ]]; then
  echo "Codex auth/config directory not found: $codex_home" >&2
  echo "Run 'codex login' on the host, or set CODEX_HOST_HOME to the directory to mount." >&2
  exit 2
fi

if ! docker image inspect "$image" >/dev/null 2>&1; then
  docker build -t "$image" "$repo_root"
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

read -r -d '' prompt <<PROMPT || true
## Overview
You are a fully autonomous security analysts that is searching the firmware we have developed for vulnerabilities.
Your name is colloquially FRIDAY.
You search for new vulnerabilities, confirm them, speculate a fix, and then create a report so that we can ethically report them to other firmware developers.

In particular, you do analysis on a type of software called firmware, which can come in two different forms:
1. Modular: many binaries are run on the system in a likely-UNIX fashion.
2. Monolithic: a single binary runs the entire system. 

All of these firmwares are for routers. 

## Environment
You are running inside a docker container, which you can install and use any tool you desire.

Firmware path inside the container:
/input/firmware

Common output directory:
/workspaces/FRIDAY/router-agent-results/$run_id

You also have two types of major tools we have pre-installed:
1. Greenhouse: an emulator for modular firmware 
2. DecLib: an interface to use decompilers for which you can do static analysis on these different binaries in the firmware

You can find other related tooling in the /input/.

## Strategy
When looking for vulnerabilities you should follow the general strategy and adapt as needed.

### Stage 1: Recon
Consider how we will realistically get input from the frontend (or sever-end) of the system to the binaries and backend that have identified vulnerabilities.
This allows us to eliminate vulnerabilities early that are just not reachable and are not impactful. 

This also means we should eliminate (with documentation that we stoped pursing it) vulnerabilties that have no impact.
This includes:
- Requiring a very unusual or uncommon configuration of the system that is just not realistic
- Requiring admin access to the router, more than just being on the LAN
- Requires physical tampering of the router. 

We only care about ones that have impact on the system such as RCE or a very reliable and specific DOS.
The general DOS is not impactful.

### Stage 2: Search
Begin searching for vulnerabilities by doing two things:

2A. Search explicitly for sinks that use `system`/`execve` and other functions that essentially use bash commands. These are easy targets for checking if we can get a command injection or access data we should not have access to
2B. Search the web for recent CVEs in THIS SPECIFIC system or very similar models. We use those CVEs to inspire where else in the router we should search for vulnerabilities, since there are often related vulns. 

You should do 2A by using common grepping and the decompiler as needed. 
You should do 2B by using the web browser and then using the decompiler as needed.

When you find a vulnerability, you should document it in the VULNERABILITIES.md, and not wether they have been confirmed yet with a PoC.


### Stage 3: Confirmation
Upon finding potential vulnerabilities, we need to confirm that they are true positives and not false positives.
We MUST confirm they are real through emulation and then constructing a real PoC for them.

1. Use `greenhouse`, which is installed in the container and at /JORDAN/SAY/THE/PATH/HERE to be used to run firmware as needed.
2. Upon using Greenhouse, this should allow you to make a Proof-of-Concept script which is a very minimal exploit to prove that the vulnerability works. It is critical that this is as realistic as possible. Mocking out functions from the binary is generally bad. We should juse use the binary. 

When confirmed, update them in VULNERABILITIES.md to say wether confirmed. Also link to the poc and put it in the output.


### Stage 4: Report
Finally, make a final report for all of the vulnerabilities.
For all of the confirmed ones, write how the PoC generally works and why the bug is real.
Also, suggest a minimal patch that could be used to fix it.
You do not need to prove that this fix is right. 



If at any stage the tooling is not helpful or is broken, note it somewhere so we can fix it. 

Return the report path, summary path, and any notable findings.
PROMPT

docker run --rm \
  --workdir /workspaces/FRIDAY \
  --volume "$repo_root:/workspaces/FRIDAY" \
  --volume "$firmware_abs:/input/firmware:ro" \
  --volume "$codex_home:/home/vscode/.codex" \
  "$image" \
  codex exec \
    --cd /workspaces/FRIDAY \
    --sandbox danger-full-access \
    --ask-for-approval never \
    --output-last-message "/workspaces/FRIDAY/router-agent-results/$run_id/codex-final.md" \
    "$prompt"
