#!/usr/bin/env python3
"""Bounded unauthenticated parser probes for the isolated RAX30 UPnP lab."""

from __future__ import annotations

import json
import socket
import time
from pathlib import Path


HOST = "127.0.0.1"
PORT = 26_688
UUID = "uuid:1a0de632-52ec-4fc2-9372-5d4b452ba131"
CONTROL_PATH = f"/{UUID}/Layer3Forwarding:1"
SERIAL = (
    Path(__file__).resolve().parents[1]
    / "known_firmware/emulation/RAX30/full-system-lab/upnp-serial.log"
)


def exchange(payload: bytes, timeout: float = 3.0) -> dict[str, object]:
    started = time.monotonic()
    response = bytearray()
    error = ""
    try:
        with socket.create_connection((HOST, PORT), timeout=timeout) as client:
            client.sendall(payload)
            client.shutdown(socket.SHUT_WR)
            while len(response) < 1024 * 1024:
                chunk = client.recv(65536)
                if not chunk:
                    break
                response.extend(chunk)
    except OSError as exc:
        error = f"{type(exc).__name__}: {exc}"
    first_line = bytes(response).splitlines()[0].decode(errors="replace") if response else ""
    return {
        "status": first_line,
        "bytes": len(response),
        "error": error,
        "elapsed_ms": round((time.monotonic() - started) * 1000, 3),
    }


def request(
    method: str,
    path: str,
    headers: list[tuple[str, str]] | None = None,
    body: bytes = b"",
) -> bytes:
    fields = [
        ("Host", "10.0.2.15:56688"),
        ("Connection", "close"),
        *(headers or []),
        ("Content-Length", str(len(body))),
    ]
    head = f"{method} {path} HTTP/1.1\r\n".encode()
    head += b"".join(f"{name}: {value}\r\n".encode() for name, value in fields)
    return head + b"\r\n" + body


def baseline() -> bool:
    result = exchange(request("GET", "/"))
    return result["status"] == "HTTP/1.1 404 Not Found"


def main() -> int:
    marker = "FRIDAY_RAX30_PROBE_7b6f2a"
    xml = (
        '<?xml version="1.0"?>'
        '<s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/">'
        "<s:Body><u:SetDefaultConnectionService "
        'xmlns:u="urn:schemas-upnp-org:service:Layer3Forwarding:1">'
        f"<NewDefaultConnectionService>{marker}</NewDefaultConnectionService>"
        "</u:SetDefaultConnectionService></s:Body></s:Envelope>"
    ).encode()
    long_values = (32, 33, 64, 128, 256, 1024, 4096, 16384)
    cases: list[tuple[str, bytes]] = [
        ("baseline_get", request("GET", "/")),
        ("description", request("GET", f"/dyndev/{UUID}")),
        (
            "soap_baseline",
            request(
                "POST",
                CONTROL_PATH,
                [
                    ("Content-Type", "text/xml"),
                    (
                        "SOAPACTION",
                        '"urn:schemas-upnp-org:service:Layer3Forwarding:1'
                        '#SetDefaultConnectionService"',
                    ),
                ],
                xml,
            ),
        ),
        (
            "subscribe_baseline",
            request(
                "SUBSCRIBE",
                CONTROL_PATH,
                [("CALLBACK", "<http://10.0.2.2:9/callback>"), ("NT", "upnp:event")],
            ),
        ),
    ]
    for size in long_values:
        value = marker + "A" * size
        cases.extend(
            [
                (f"path_{size}", request("GET", "/" + value)),
                (f"host_{size}", request("GET", "/", [("Host", value)])),
                (
                    f"soapaction_{size}",
                    request(
                        "POST",
                        CONTROL_PATH,
                        [("Content-Type", "text/xml"), ("SOAPACTION", f'"{value}"')],
                        xml,
                    ),
                ),
                (
                    f"callback_{size}",
                    request(
                        "SUBSCRIBE",
                        CONTROL_PATH,
                        [("CALLBACK", f"<http://10.0.2.2/{value}>"), ("NT", "upnp:event")],
                    ),
                ),
                (
                    f"xml_value_{size}",
                    request(
                        "POST",
                        CONTROL_PATH,
                        [
                            ("Content-Type", "text/xml"),
                            (
                                "SOAPACTION",
                                '"urn:schemas-upnp-org:service:Layer3Forwarding:1'
                                '#SetDefaultConnectionService"',
                            ),
                        ],
                        xml.replace(marker.encode(), value.encode()),
                    ),
                ),
            ]
        )

    serial_offset = SERIAL.stat().st_size if SERIAL.exists() else 0
    results = []
    for name, payload in cases:
        outcome = exchange(payload)
        time.sleep(0.05)
        healthy = baseline()
        results.append({"case": name, "request_bytes": len(payload), **outcome, "healthy": healthy})
        print(
            f"{name}: status={outcome['status']!r} error={outcome['error']!r} "
            f"healthy={healthy}",
            flush=True,
        )
        if not healthy:
            break

    time.sleep(1)
    new_serial = (
        SERIAL.read_text(errors="replace")[serial_offset:] if SERIAL.exists() else ""
    )
    signals = {
        "long_strcpy": new_serial.count("FRIDAY_RAX30_LONG_STRCPY"),
        "probe_marker_visible": marker in new_serial,
        "daemon_exit": "UPNP_EXITED=1" in new_serial,
        "kernel_fault": any(
            token in new_serial
            for token in ("Kernel panic", "segfault", "Unhandled fault", "stack smashing")
        ),
    }
    output = {"cases": results, "signals": signals, "serial_tail": new_serial.splitlines()[-120:]}
    print(json.dumps(output, indent=2))
    return 1 if any(not row["healthy"] for row in results) or signals["daemon_exit"] else 0


if __name__ == "__main__":
    raise SystemExit(main())
