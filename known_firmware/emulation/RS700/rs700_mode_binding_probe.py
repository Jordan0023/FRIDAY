#!/usr/bin/env python3
"""Record genuine RS700 upnpd listeners under bounded representative mode flags."""

from __future__ import annotations

import json
import subprocess
import time


MODES = (
    (
        "router_default",
        {
            "router_disable": "0",
            "enable_ap_mode": "0",
            "enable_extender_mode": "0",
            "remote_mg_enable": "0",
        },
    ),
    (
        "remote_management_enabled",
        {
            "router_disable": "0",
            "enable_ap_mode": "0",
            "enable_extender_mode": "0",
            "remote_mg_enable": "1",
            "remote_port_num": "8443",
        },
    ),
    (
        "ap_mode_flags",
        {
            "router_disable": "1",
            "enable_ap_mode": "1",
            "enable_extender_mode": "0",
            "remote_mg_enable": "0",
        },
    ),
    (
        "bridge_extender_flags",
        {
            "router_disable": "1",
            "enable_ap_mode": "0",
            "enable_extender_mode": "1",
            "remote_mg_enable": "0",
        },
    ),
)


def run(*command: str, check: bool = True) -> subprocess.CompletedProcess[str]:
    return subprocess.run(command, check=check, text=True, capture_output=True)


def nvram_set(setting: str) -> None:
    run("chroot", "/fw", "/qemu-arm-static", "/bin/acos_nvram", "set", setting)


def stop_daemon() -> None:
    result = run("pgrep", "-f", "^/qemu-arm-static /usr/sbin/upnpd$", check=False)
    for pid in result.stdout.split():
        run("kill", pid, check=False)
    time.sleep(0.3)


def listeners() -> list[str]:
    result = run("ss", "-H", "-lntup")
    return sorted(
        line.strip()
        for line in result.stdout.splitlines()
        if ":56688" in line or ":1900" in line
    )


def start_daemon() -> None:
    subprocess.run(
        ("chroot", "/fw", "/qemu-arm-static", "/usr/sbin/upnpd"),
        check=True,
        stdin=subprocess.DEVNULL,
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
    )


def main() -> None:
    records = []
    for name, settings in MODES:
        stop_daemon()
        for key, value in settings.items():
            nvram_set(f"{key}={value}")
        start_daemon()
        time.sleep(1)
        records.append({"mode": name, "settings": settings, "listeners": listeners()})
    print(json.dumps(records, indent=2, sort_keys=True))


if __name__ == "__main__":
    main()
