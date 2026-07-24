#!/usr/bin/env python3
"""Isolated simultaneous LAN/WAN GT-BE98 Pro wl_server_socket lab."""

from __future__ import annotations

import json
import subprocess
import time
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
ROOTFS = next(
    (ROOT / "known_firmware/extracted/e9c3bdc196cdc005").glob(
        "**/squashfs-root/usr/sbin/wl_server_socket"
    )
).parents[2]
IMAGE = "friday-hacker-agent:latest"
ROUTER = "gtbe98-wl-dual-router"
LAN_CLIENT = "gtbe98-wl-dual-lan-client"
WAN_CLIENT = "gtbe98-wl-dual-wan-client"
LAN_NET = "gtbe98-wl-dual-lan"
WAN_NET = "gtbe98-wl-dual-wan"
LAN_IP = "172.31.98.2"
WAN_IP = "172.31.99.2"


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


def start(interface: str) -> None:
    docker(
        "exec", "-d", ROUTER, "/usr/bin/qemu-arm-static",
        "-L", "/firmware", "/firmware/usr/sbin/wl_server_socket",
        "-b", interface, "8000",
    )


def reachable(container: str, address: str) -> bool:
    return docker(
        "exec", container, "nc", "-z", "-w", "2", address, "8000",
        check=False,
    ).returncode == 0


def marker(container: str, address: str, name: str) -> bool:
    code = (
        "import socket,struct;"
        f"c=b'echo {name} > /tmp/{name}\\0';"
        f"s=socket.create_connection(('{address}',8000),3);"
        "s.sendall(struct.pack('<9I',0,len(c),8,0,len(c),0,0,0,0)+c);"
        "s.close()"
    )
    if docker("exec", container, "python3", "-c", code, check=False).returncode:
        return False
    time.sleep(0.5)
    return docker(
        "exec", ROUTER, "sh", "-c",
        f"test \"$(cat /tmp/{name} 2>/dev/null)\" = {name}",
        check=False,
    ).returncode == 0


def main() -> int:
    cleanup()
    try:
        docker(
            "network", "create", "--internal", "--subnet",
            "172.31.98.0/24", LAN_NET,
        )
        docker(
            "network", "create", "--internal", "--subnet",
            "172.31.99.0/24", WAN_NET,
        )
        docker(
            "run", "-d", "--name", ROUTER, "--user", "root",
            "--cap-add", "NET_ADMIN", "--network", WAN_NET, "--ip", WAN_IP,
            "-v", f"{ROOTFS}:/firmware:ro", IMAGE, "sleep", "infinity",
        )
        docker("network", "connect", "--ip", LAN_IP, LAN_NET, ROUTER)
        docker(
            "run", "-d", "--name", LAN_CLIENT, "--network", LAN_NET,
            "--ip", "172.31.98.10", IMAGE, "sleep", "infinity",
        )
        docker(
            "run", "-d", "--name", WAN_CLIENT, "--network", WAN_NET,
            "--ip", "172.31.99.10", IMAGE, "sleep", "infinity",
        )

        interfaces = json.loads(
            docker("exec", ROUTER, "ip", "-j", "-4", "addr", "show").stdout
        )
        by_address = {
            info["local"]: item["ifname"]
            for item in interfaces
            for info in item.get("addr_info", [])
        }
        if by_address[WAN_IP] != "eth0":
            raise RuntimeError(f"WAN did not resolve to eth0: {by_address}")
        lan_device = by_address[LAN_IP]
        docker("exec", ROUTER, "ip", "link", "set", lan_device, "down")
        docker("exec", ROUTER, "ip", "link", "set", lan_device, "name", "br0")
        docker("exec", ROUTER, "ip", "link", "set", "br0", "up")
        docker("exec", ROUTER, "mkdir", "-p", "/tmp/RWL")

        # Two instances listen on the same TCP port but different interface IPs.
        start("eth0")
        start("br0")
        time.sleep(1)

        results = {
            "isolated": True,
            "published_host_ports": [],
            "listeners": {
                "wan_eth0_8000": reachable(WAN_CLIENT, WAN_IP),
                "lan_br0_8000": reachable(LAN_CLIENT, LAN_IP),
            },
            "fixed_markers": {
                "wan": marker(
                    WAN_CLIENT, WAN_IP, "FRIDAY_GTBE98_DUAL_WAN"
                ),
                "lan": marker(
                    LAN_CLIENT, LAN_IP, "FRIDAY_GTBE98_DUAL_LAN"
                ),
            },
            "segmentation": {
                "wan_cannot_reach_lan_address":
                    not reachable(WAN_CLIENT, LAN_IP),
                "lan_cannot_reach_wan_address":
                    not reachable(LAN_CLIENT, WAN_IP),
            },
        }
        print(json.dumps(results, indent=2))
        passed = all(results["listeners"].values())
        passed &= all(results["fixed_markers"].values())
        passed &= all(results["segmentation"].values())
        return 0 if passed else 1
    finally:
        cleanup()


if __name__ == "__main__":
    raise SystemExit(main())
