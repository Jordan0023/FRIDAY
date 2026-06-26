#!/usr/bin/env bash
set -euo pipefail

PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
RUNNER="$PROJECT_DIR/scripts/netgear-watch-daily.sh"
SYSTEMD_USER_DIR="$HOME/.config/systemd/user"
SERVICE="$SYSTEMD_USER_DIR/netgear-firmware-watch.service"
TIMER="$SYSTEMD_USER_DIR/netgear-firmware-watch.timer"

mkdir -p "$SYSTEMD_USER_DIR"
chmod +x "$RUNNER"

cat > "$SERVICE" <<UNIT
[Unit]
Description=Check for new Netgear firmware

[Service]
Type=oneshot
WorkingDirectory=$PROJECT_DIR
ExecStart=$RUNNER
UNIT

cat > "$TIMER" <<UNIT
[Unit]
Description=Run Netgear firmware watcher daily

[Timer]
OnCalendar=daily
Persistent=true
RandomizedDelaySec=30m
Unit=netgear-firmware-watch.service

[Install]
WantedBy=timers.target
UNIT

systemctl --user daemon-reload
systemctl --user enable --now netgear-firmware-watch.timer
systemctl --user list-timers netgear-firmware-watch.timer
