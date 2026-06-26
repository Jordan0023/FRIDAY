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
exec "$PYTHON" netgear_watch_new.py --use-browser --analyze --limit-products 10 --limit-firmware 1 >> "$LOG_DIR/daily-watch.log" 2>&1
