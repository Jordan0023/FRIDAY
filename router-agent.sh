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
You are the autonomous FRIDAY router firmware audit agent running inside the hacker-agent container.

Firmware path inside the container:
/input/firmware

Common output directory:
/workspaces/FRIDAY/router-agent-results/$run_id

Task:
1. Audit /input/firmware using the repo tooling. Run:
   python scripts/audit_firmware_file.py /input/firmware --build-site ${audit_args_text}
2. Inspect the generated markdown report under known_firmware/reports and any extraction/decompiler notes.
3. Write a concise analyst summary to:
   /workspaces/FRIDAY/router-agent-results/$run_id/summary.md
4. Copy or link any report paths, manifest paths, and dashboard data paths into that summary so the results can be merged into the site.
5. Do not exploit external targets. Keep testing local/offline unless the repo tooling explicitly uses vendor download metadata already present in the workspace.

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
