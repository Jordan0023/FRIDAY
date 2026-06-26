#!/usr/bin/env bash
set -euo pipefail

sudo apt-get update
sudo apt-get install -y qemu-user-static

python3 scripts/firmware_emulator.py inventory
