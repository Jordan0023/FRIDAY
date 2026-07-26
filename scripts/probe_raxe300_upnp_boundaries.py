#!/usr/bin/env python3
"""Bounded unauthenticated UPnP parser probes for the isolated RAXE300-equivalent lab."""

from __future__ import annotations

import json
import re
import socket
import time
from pathlib import Path


HOST = "127.0.0.1"
SSDP_PORT = 39121
HTTP_PORT = 39122
OUTPUT = Path(
    "known_firmware/emulation/RAXE300/upnp-boundary-matrix.json"
)


def discover() -> tuple[str, str]:
    request = (
        b"M-SEARCH * HTTP/1.1\r\n"
        b"HOST: 239.255.255.250:1900\r\n"
        b'MAN: \"ssdp:discover\"\r\n'
        b"MX: 1\r\n"
        b"ST: upnp:rootdevice\r\n\r\n"
    )
    try:
        with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as client:
            client.settimeout(3)
            client.sendto(request, (HOST, SSDP_PORT))
            response = client.recv(8192).decode("latin-1", errors="replace")
    except TimeoutError:
        # QEMU user-mode UDP forwarding can drop the reply even though the
        # genuine guest probe reaches SSDP. Use that captured positive-control
        # response rather than inventing a device UUID.
        serial = Path(
            "known_firmware/emulation/RAXE290/full-system-lab/upnp-serial.log"
        )
        response = serial.read_text(errors="replace")
    match = re.search(r"(?im)^Location:\s*http://[^/]+(/dyndev/(uuid:[0-9a-f-]+))", response)
    if not match:
        raise RuntimeError(f"SSDP response lacked a usable Location: {response!r}")
    return match.group(1), match.group(2)


def exchange(payload: bytes, limit: int = 8192) -> bytes:
    response = bytearray()
    with socket.create_connection((HOST, HTTP_PORT), timeout=4) as client:
        client.settimeout(3)
        client.sendall(payload)
        client.shutdown(socket.SHUT_WR)
        try:
            while len(response) < limit:
                chunk = client.recv(min(4096, limit - len(response)))
                if not chunk:
                    break
                response.extend(chunk)
        except (TimeoutError, ConnectionResetError):
            pass
    return bytes(response)


def status(payload: bytes) -> str:
    try:
        response = exchange(payload)
        return response.splitlines()[0].decode("latin-1", errors="replace") if response else "no response"
    except OSError as error:
        return f"{type(error).__name__}: {error}"


def alive(root_path: str) -> bool:
    del root_path
    try:
        with socket.create_connection((HOST, HTTP_PORT), timeout=2):
            pass
    except OSError:
        return False
    serial = Path(
        "known_firmware/emulation/RAXE290/full-system-lab/upnp-serial.log"
    ).read_text(errors="replace")
    return "UPNP_HEALTH_PID=" in serial and not any(
        marker in serial
        for marker in ("UPNP_EXITED=1", "FRIDAY_RAX30_FATAL", "Segmentation fault")
    )


def main() -> int:
    root_path, uuid = discover()
    service = f"/{uuid}/Layer3Forwarding:1"
    long_value = b"A" * 65536
    cases = {
        "callback_256": (
            f"SUBSCRIBE {service} HTTP/1.1\r\nHost: 10.0.2.15:56688\r\n".encode()
            + b"CALLBACK: <http://10.0.2.2/" + b"A" * 256
            + b">\r\nNT: upnp:event\r\nContent-Length: 0\r\n\r\n"
        ),
        "callback_4096": (
            f"SUBSCRIBE {service} HTTP/1.1\r\nHost: 10.0.2.15:56688\r\n".encode()
            + b"CALLBACK: <http://10.0.2.2/" + b"A" * 4096
            + b">\r\nNT: upnp:event\r\nContent-Length: 0\r\n\r\n"
        ),
        "callback_65536": (
            f"SUBSCRIBE {service} HTTP/1.1\r\nHost: 10.0.2.15:56688\r\n".encode()
            + b"CALLBACK: <http://10.0.2.2/" + long_value
            + b">\r\nNT: upnp:event\r\nContent-Length: 0\r\n\r\n"
        ),
        "sid_4096": (
            f"UNSUBSCRIBE {service} HTTP/1.1\r\nHost: 10.0.2.15:56688\r\nSID: uuid:".encode()
            + b"B" * 4096 + b"\r\n\r\n"
        ),
        "soapaction_4096": (
            f"POST /{uuid}/WANIPConnection:1 HTTP/1.1\r\nHost: 10.0.2.15:56688\r\n".encode()
            + b"SOAPACTION: \"" + b"C" * 4096
            + b"\"\r\nContent-Length: 0\r\n\r\n"
        ),
        "content_length_negative": (
            f"POST /{uuid}/WANIPConnection:1 HTTP/1.1\r\nHost: x\r\n"
            "Content-Length: -1\r\n\r\n".encode()
        ),
        "content_length_overflow": (
            f"POST /{uuid}/WANIPConnection:1 HTTP/1.1\r\nHost: x\r\n"
            "Content-Length: 4294967295\r\n\r\n".encode()
        ),
        "request_target_8192": (
            b"GET /" + b"D" * 8192 + b" HTTP/1.1\r\nHost: x\r\n\r\n"
        ),
        "header_value_65536": (
            f"GET {root_path} HTTP/1.1\r\nHost: x\r\nX-Friday: ".encode()
            + long_value + b"\r\n\r\n"
        ),
        "many_headers": (
            f"GET {root_path} HTTP/1.1\r\nHost: x\r\n".encode()
            + b"".join(f"X-F-{index}: A\r\n".encode() for index in range(1024))
            + b"\r\n"
        ),
    }
    results: list[dict[str, object]] = []
    baseline = alive(root_path)
    for name, payload in cases.items():
        result = status(payload)
        time.sleep(0.5)
        healthy = alive(root_path)
        results.append(
            {
                "case": name,
                "request_bytes": len(payload),
                "status": result,
                "service_alive": healthy,
            }
        )
        if not healthy:
            break
    udp_results: list[dict[str, object]] = []
    if alive(root_path):
        udp_cases = {
            "ssdp_st_4096": (
                b"M-SEARCH * HTTP/1.1\r\nHOST: 239.255.255.250:1900\r\n"
                b'MAN: "ssdp:discover"\r\nMX: 1\r\nST: ' + b"E" * 4096 + b"\r\n\r\n"
            ),
            "ssdp_man_4096": (
                b"M-SEARCH * HTTP/1.1\r\nHOST: 239.255.255.250:1900\r\nMAN: "
                + b"F" * 4096 + b"\r\nMX: 1\r\nST: upnp:rootdevice\r\n\r\n"
            ),
            "ssdp_mx_4096": (
                b"M-SEARCH * HTTP/1.1\r\nHOST: 239.255.255.250:1900\r\n"
                b'MAN: "ssdp:discover"\r\nMX: ' + b"9" * 4096
                + b"\r\nST: upnp:rootdevice\r\n\r\n"
            ),
            "ssdp_host_4096": (
                b"M-SEARCH * HTTP/1.1\r\nHOST: " + b"G" * 4096
                + b"\r\nMAN: \"ssdp:discover\"\r\nMX: 1\r\nST: upnp:rootdevice\r\n\r\n"
            ),
            "ssdp_target_4096": (
                b"M-SEARCH /" + b"H" * 4096
                + b" HTTP/1.1\r\nHOST: 239.255.255.250:1900\r\n"
                b'MAN: "ssdp:discover"\r\nMX: 1\r\nST: upnp:rootdevice\r\n\r\n'
            ),
            "ssdp_datagram_60000": (
                b"M-SEARCH * HTTP/1.1\r\nHOST: 239.255.255.250:1900\r\n"
                b'MAN: "ssdp:discover"\r\nMX: 1\r\nST: '
                + b"I" * 59900 + b"\r\n\r\n"
            ),
        }
        for name, payload in udp_cases.items():
            try:
                with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as client:
                    sent = client.sendto(payload, (HOST, SSDP_PORT))
                send_result = f"sent={sent}"
            except OSError as error:
                send_result = f"{type(error).__name__}: {error}"
            time.sleep(1)
            healthy = alive(root_path)
            udp_results.append(
                {
                    "case": name,
                    "request_bytes": len(payload),
                    "send_result": send_result,
                    "service_alive": healthy,
                }
            )
            if not healthy:
                break
    document = {
        "product": "RAXE300 V1.0.9.82 (byte-identical RAXE290 UPnP full-system runtime)",
        "root_path": root_path,
        "baseline": baseline,
        "results": results,
        "udp_results": udp_results,
        "final_alive": alive(root_path),
    }
    OUTPUT.parent.mkdir(parents=True, exist_ok=True)
    OUTPUT.write_text(json.dumps(document, indent=2) + "\n")
    print(json.dumps(document, indent=2))
    return 0 if baseline and document["final_alive"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
