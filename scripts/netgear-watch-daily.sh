#!/usr/bin/env bash
set -euo pipefail

PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
LOG_DIR="$PROJECT_DIR/known_firmware/logs"
mkdir -p "$LOG_DIR"

if [[ -x "$PROJECT_DIR/.venv/bin/python" ]]; then
  PYTHON="$PROJECT_DIR/.venv/bin/python"
else
  PYTHON="python3"
fi

cd "$PROJECT_DIR"
STATUS=0

run_step() {
  local name="$1"
  local code=0
  shift
  echo "=== $(date -Is) $name ==="
  "$@" || code=$?
  if [[ "$code" -ne 0 ]]; then
    echo "$name failed with exit $code"
    STATUS=1
  fi
}

{
  run_step "Netgear" "$PYTHON" netgear_watch_new.py --use-browser --analyze --limit-firmware 1 --skip-site-data
  run_step "ASUS" "$PYTHON" asus_full_download.py --analyze --limit-firmware 1
  run_step "TP-Link" "$PYTHON" tplink_full_download.py --analyze --limit-firmware 1
  run_step "GL.iNet" "$PYTHON" glinet_full_download.py --analyze --limit-firmware 1
  run_step "OpenWrt" "$PYTHON" openwrt_full_download.py --analyze --limit-firmware 1
  run_step "Dashboard" "$PYTHON" scripts/build_site_data.py
} >> "$LOG_DIR/daily-watch.log" 2>&1

exit "$STATUS"
