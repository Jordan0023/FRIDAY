#!/usr/bin/env python3
"""Bounded RS700 UPnP validation probe; loopback-only unless explicitly allowed."""

from __future__ import annotations

import argparse
import http.client
import ipaddress
import json
import socket
from dataclasses import dataclass


CANARY = "FRIDAY_RS700_CANARY"
SOAP_PATH = "/Public_UPNP_C3"
EVENT_PATH = "/Public_UPNP_Event_3"


@dataclass(frozen=True)
class Case:
    name: str
    method: str
    path: str
    headers: dict[str, str]
    body: bytes = b""


def envelope(action: str, fields: list[tuple[str, str]], service: str = "WANIPConnection") -> bytes:
    elements = "".join(f"<{name}>{value}</{name}>" for name, value in fields)
    return (
        '<?xml version="1.0"?>'
        '<s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/" '
        's:encodingStyle="http://schemas.xmlsoap.org/soap/encoding/">'
        f'<s:Body><u:{action} xmlns:u="urn:schemas-upnp-org:service:{service}:1">'
        f"{elements}</u:{action}></s:Body></s:Envelope>"
    ).encode()


def soap_case(name: str, action: str, fields: list[tuple[str, str]]) -> Case:
    return Case(
        name,
        "POST",
        SOAP_PATH,
        {
            "Content-Type": 'text/xml; charset="utf-8"',
            "SOAPAction": f'"urn:schemas-upnp-org:service:WANIPConnection:1#{action}"',
        },
        envelope(action, fields),
    )


def mapping_fields(**changes: str) -> list[tuple[str, str]]:
    values = {
        "NewRemoteHost": "",
        "NewExternalPort": "54321",
        "NewProtocol": "TCP",
        "NewInternalPort": "54321",
        "NewInternalClient": "192.168.1.2",
        "NewEnabled": "1",
        "NewPortMappingDescription": "friday-control",
        "NewLeaseDuration": "0",
    }
    values.update(changes)
    return list(values.items())


def cases() -> list[Case]:
    result = [soap_case("mapping_control", "AddPortMapping", mapping_fields())]
    mutations = {
        "remote_host_semicolon": ("NewRemoteHost", f"1.2.3.4;{CANARY}"),
        "external_port_semicolon": ("NewExternalPort", f"54321;{CANARY}"),
        "protocol_semicolon": ("NewProtocol", f"TCP;{CANARY}"),
        "internal_port_semicolon": ("NewInternalPort", f"54321;{CANARY}"),
        "internal_client_semicolon": ("NewInternalClient", f"192.168.1.2;{CANARY}"),
        "description_semicolon": ("NewPortMappingDescription", f"x;{CANARY}"),
        "description_subshell": ("NewPortMappingDescription", f"$({CANARY})"),
        "description_backtick": ("NewPortMappingDescription", f"`{CANARY}`"),
        "description_newline": ("NewPortMappingDescription", f"x&#10;{CANARY}"),
        "protocol_whitespace": ("NewProtocol", f"TCP {CANARY}"),
        "internal_client_whitespace": ("NewInternalClient", f"192.168.1.2 {CANARY}"),
    }
    for name, (field, value) in mutations.items():
        result.append(soap_case(name, "AddPortMapping", mapping_fields(**{field: value})))
    for size in (64, 256, 1024, 1600, 2048, 4096):
        result.append(
            soap_case(
                f"description_length_{size}",
                "AddPortMapping",
                mapping_fields(NewPortMappingDescription="A" * size),
            )
        )
    event_headers = [
        ("event_control", {"CALLBACK": "<http://192.168.1.2:18080/event>", "NT": "upnp:event", "TIMEOUT": "Second-1800"}),
        ("event_callback_semicolon", {"CALLBACK": f"<http://192.168.1.2:18080/{CANARY};x>", "NT": "upnp:event", "TIMEOUT": "Second-1800"}),
        ("event_callback_long", {"CALLBACK": f"<http://192.168.1.2:18080/{'A' * 4096}>", "NT": "upnp:event", "TIMEOUT": "Second-1800"}),
        ("event_timeout_semicolon", {"CALLBACK": "<http://192.168.1.2:18080/event>", "NT": "upnp:event", "TIMEOUT": f"Second-1;{CANARY}"}),
        ("event_missing_callback", {"NT": "upnp:event", "TIMEOUT": "Second-1800"}),
    ]
    result.extend(Case(name, "SUBSCRIBE", EVENT_PATH, headers) for name, headers in event_headers)
    private = [
        ("private_speedtest_no_auth", "SetOOKLASpeedTestStart"),
        ("private_firmware_no_auth", "SetFirmware"),
        ("private_config_no_auth", "SetConfiguration"),
    ]
    for name, action in private:
        result.append(
            Case(
                name,
                "POST",
                "/soap/server_sa",
                {
                    "Content-Type": 'text/xml; charset="utf-8"',
                    "SOAPAction": f'"urn:NETGEAR-ROUTER:service:DeviceConfig:1#{action}"',
                },
                envelope(action, [("NewValue", f"x;{CANARY}")], "DeviceConfig"),
            )
        )
    return result


def request(host: str, port: int, case: Case) -> tuple[int | None, str]:
    connection = http.client.HTTPConnection(host, port, timeout=3)
    try:
        connection.request(case.method, case.path, body=case.body, headers=case.headers)
        response = connection.getresponse()
        data = response.read(4096)
        return response.status, data.decode(errors="replace")
    except (ConnectionError, TimeoutError, OSError, http.client.HTTPException) as error:
        return None, f"{type(error).__name__}: {error}"
    finally:
        connection.close()


def healthy(host: str, port: int) -> bool:
    status, _ = request(host, port, Case("health", "GET", "/Public_UPNP_gatedesc.xml", {}))
    return status is not None


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--host", default="127.0.0.1")
    parser.add_argument("--port", type=int, default=56688)
    parser.add_argument("--allow-non-loopback", action="store_true")
    args = parser.parse_args()
    address = ipaddress.ip_address(socket.gethostbyname(args.host))
    if not address.is_loopback and not args.allow_non_loopback:
        parser.error("non-loopback target refused; opt in only inside an isolated lab")
    for case in cases():
        status, detail = request(args.host, args.port, case)
        print(
            json.dumps(
                {
                    "case": case.name,
                    "status": status,
                    "response_prefix": detail[:160],
                    "healthy_after": healthy(args.host, args.port),
                },
                sort_keys=True,
            ),
            flush=True,
        )


if __name__ == "__main__":
    main()
