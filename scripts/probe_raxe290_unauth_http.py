#!/usr/bin/env python3
"""Bounded unauthenticated HTTP boundary probes for the isolated RAXE290 lab."""

from __future__ import annotations

import http.client
import json
import socket
import sys
from pathlib import Path


HOST, PORT = "127.0.0.1", 25291
PATHS = (
    "/",
    "/currentsetting.htm",
    "/debuginfo.htm",
    "/LGO_logout.html",
    "/jdoedw18ge",
    "/acblock.htm2",
    "/tm_block",
    "/passwordrecovered.cgi",
    "/password_reset.php",
    "/pwd_reset/pwd_reset_checkSN.html",
    "/pwd_reset/pwd_reset_checkAnswer.html",
    "/pwd_reset/reset_pwd.cgi",
    "/php/checkAnswer_data.php",
    "/php/db/password_data.php",
    "/php/db/usb_data.php",
    "/php/usb.php",
    "/cgi-bin/",
    "/soap/server_sa/",
)


def request(method: str, path: str, body: bytes = b"") -> dict[str, object]:
    conn = http.client.HTTPConnection(HOST, PORT, timeout=5)
    try:
        conn.request(method, path, body, {"Content-Type": "application/x-www-form-urlencoded"})
        response = conn.getresponse()
        data = response.read(4096)
        return {
            "method": method,
            "path": path,
            "status": response.status,
            "bytes_sampled": len(data),
            "location": response.getheader("Location"),
            "www_authenticate": response.getheader("WWW-Authenticate"),
        }
    except (OSError, http.client.HTTPException) as error:
        return {"method": method, "path": path, "error": f"{type(error).__name__}: {error}"}
    finally:
        conn.close()


def ipp_open() -> bool:
    try:
        with socket.create_connection((HOST, 39633), timeout=1) as client:
            client.sendall(
                b"GET /printers/lab HTTP/1.0\r\nHost: 10.0.2.15:631\r\n\r\n"
            )
            client.shutdown(socket.SHUT_WR)
            return client.recv(16).startswith(b"HTTP/")
    except OSError:
        return False


def main() -> int:
    results = [request("GET", path) for path in PATHS]
    # Exercise recovery/setup handlers with inert values and a bounded parser case.
    results.extend((
        request("POST", "/passwordrecovered.cgi", b"serial=FRIDAY_INVALID"),
        request("POST", "/php/checkAnswer_data.php", b"answer1=FRIDAY_INVALID&answer2=FRIDAY_INVALID"),
        request("POST", "/pwd_reset/reset_pwd.cgi", b"action=checkSN&serialNumber=FRIDAY_INVALID"),
        request(
            "POST",
            "/pwd_reset/reset_pwd.cgi",
            b"action=checkAnswer&answer1=RlJJREFZX0lOVkFMSUQ=&answer2=RlJJREFZX0lOVkFMSUQ=",
        ),
        request("GET", "/" + "A" * 4096),
    ))
    document = {"ipp_before": ipp_open(), "results": results, "ipp_after": ipp_open()}
    rendered = json.dumps(document, indent=2)
    output = (
        Path(__file__).resolve().parents[1]
        / "known_firmware/emulation/RAXE290/soap-full-system-lab/unauth-http-matrix.json"
    )
    output.write_text(rendered + "\n")
    print(rendered)
    print(f"output={output}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
