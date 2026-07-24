#!/bin/sh
set -eu

repo_dir=$(CDPATH= cd -- "$(dirname -- "$0")/.." && pwd)
docker run --rm \
  --network none \
  --user "$(id -u):$(id -g)" \
  -v "$repo_dir:$repo_dir" \
  -v /tmp/qemu-user-static-local/usr/bin/qemu-arm-static:/tmp/qemu-user-static-local/usr/bin/qemu-arm-static:ro \
  -w "$repo_dir" \
  friday-hacker-agent:latest \
  python3 scripts/validate_ad7200_qcmbr.py
