#!/usr/bin/env python3
"""Deep bounded audit of genuine RAX9 IGD, WPS, and eventing parsers."""

from __future__ import annotations

import base64
import json
import socket
import time


HOST = "127.0.0.1"
IGD_PORT = 56688
WPS_PORT = 8888


def alive(port: int) -> bool:
    try:
        with socket.create_connection((HOST, port), timeout=0.5):
            return True
    except OSError:
        return False


def exchange(port: int, request: bytes) -> dict[str, object]:
    result: dict[str, object] = {"sent": len(request)}
    try:
        with socket.create_connection((HOST, port), timeout=1.0) as sock:
            sock.settimeout(1.5)
            sock.sendall(request)
            chunks = []
            while sum(map(len, chunks)) < 4096:
                try:
                    chunk = sock.recv(4096)
                except socket.timeout:
                    break
                if not chunk:
                    break
                chunks.append(chunk)
        response = b"".join(chunks)
        result["response_bytes"] = len(response)
        result["status"] = response.split(b"\r\n", 1)[0].decode("latin-1", "replace")
    except OSError as error:
        result["error"] = f"{type(error).__name__}: {error}"
    return result


def soap(port: int, path: str, service: str, action: str, inner: str) -> bytes:
    body = (
        '<?xml version="1.0"?>'
        '<s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/" '
        's:encodingStyle="http://schemas.xmlsoap.org/soap/encoding/">'
        f'<s:Body><u:{action} xmlns:u="{service}">{inner}</u:{action}></s:Body>'
        "</s:Envelope>"
    ).encode()
    return (
        f"POST /{path} HTTP/1.1\r\n"
        f"Host: {HOST}:{port}\r\n"
        f'SOAPAction: "{service}#{action}"\r\n'
        "Content-Type: text/xml; charset=utf-8\r\n"
        f"Content-Length: {len(body)}\r\n\r\n"
    ).encode() + body


def subscribe(port: int, path: str, callback: str) -> bytes:
    return (
        f"SUBSCRIBE /{path} HTTP/1.1\r\n"
        f"Host: {HOST}:{port}\r\n"
        f"CALLBACK: <{callback}>\r\n"
        "NT: upnp:event\r\n"
        "TIMEOUT: Second-30\r\n\r\n"
    ).encode()


def main() -> None:
    igd = "urn:schemas-upnp-org:service:WANIPConnection:1"
    wps = "urn:schemas-wifialliance-org:service:WFAWLANConfig:1"
    cases: list[tuple[str, int, bytes]] = [
        ("igd_control", IGD_PORT, soap(IGD_PORT, "ctl/IPConn", igd, "GetExternalIPAddress", "")),
    ]

    for size in (256, 1024, 4096, 16384):
        marker = "FRIDAY_RAX9_DESC_" + "D" * size
        inner = (
            "<NewRemoteHost></NewRemoteHost><NewExternalPort>45678</NewExternalPort>"
            "<NewProtocol>TCP</NewProtocol><NewInternalPort>45678</NewInternalPort>"
            "<NewInternalClient>127.0.0.1</NewInternalClient><NewEnabled>1</NewEnabled>"
            f"<NewPortMappingDescription>{marker}</NewPortMappingDescription>"
            "<NewLeaseDuration>60</NewLeaseDuration>"
        )
        cases.append((f"igd_description_{size}", IGD_PORT, soap(IGD_PORT, "ctl/IPConn", igd, "AddPortMapping", inner)))

    for action, field in (
        ("PutMessage", "NewInMessage"),
        ("SetSelectedRegistrar", "NewMessage"),
        ("GetAPSettings", "NewMessage"),
        ("ResetAP", "NewMessage"),
    ):
        for size in (256, 1024, 4096, 16384):
            encoded = base64.b64encode((b"FRIDAY_RAX9_WPS_" + b"W" * size)).decode()
            inner = f"<{field}>{encoded}</{field}>"
            cases.append((f"wps_{action}_{size}", WPS_PORT, soap(WPS_PORT, "control", wps, action, inner)))

    for size in (256, 1024, 4096):
        callback = "http://127.0.0.1/FRIDAY_RAX9_EVENT_" + "E" * size
        cases.append((f"igd_event_{size}", IGD_PORT, subscribe(IGD_PORT, "evt/IPConn", callback)))
        cases.append((f"wps_event_{size}", WPS_PORT, subscribe(WPS_PORT, "event", callback)))

    output = {}
    for name, port, payload in cases:
        before = alive(port)
        outcome = exchange(port, payload)
        time.sleep(0.1)
        after = alive(port)
        output[name] = {"port": port, "alive_before": before, "alive_after": after, **outcome}
        print(json.dumps({name: output[name]}, sort_keys=True), flush=True)
        if before and not after:
            break

    print(json.dumps(output, indent=2, sort_keys=True))


if __name__ == "__main__":
    main()
