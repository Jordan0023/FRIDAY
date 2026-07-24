#!/usr/bin/env python3
"""Bounded pre-authentication recovery parser probes for the RAX36 lab."""

from __future__ import annotations

import argparse
import base64
import http.client
import re
import time
import urllib.parse


HOST = "127.0.0.1"
PORT = 25137


def request(
    method: str, path: str, body: bytes = b"", *, port: int = PORT
) -> tuple[int, bytes]:
    connection = http.client.HTTPConnection(HOST, port, timeout=8)
    headers = {"Connection": "close", "Host": "routerlogin.net"}
    if body:
        headers["Content-Type"] = "application/x-www-form-urlencoded"
        headers["Content-Length"] = str(len(body))
    try:
        connection.request(method, path, body=body, headers=headers)
        response = connection.getresponse()
        return response.status, response.read(1024 * 1024)
    finally:
        connection.close()


def healthy(port: int = PORT) -> bool:
    try:
        status, body = request("GET", "/unauth.cgi", port=port)
        return status == 200 and b"enable_recovery" in body
    except (OSError, TimeoutError, http.client.HTTPException):
        return False


def page_recovery_path(page: str, port: int = PORT) -> tuple[str, bytes]:
    status, body = request("GET", page, port=port)
    if status != 200:
        raise RuntimeError(f"{page} returned HTTP {status}")
    match = re.search(br'action="(/recover\.cgi\?[^"]+)"', body)
    if not match:
        raise RuntimeError(f"recovery form action was not present on {page}")
    path = match.group(1).decode("ascii").replace(" ", "%20")
    return path, body


def recovery_path(port: int = PORT) -> str:
    return page_recovery_path("/unauth.cgi", port)[0]


def redirect_target(body: bytes) -> str | None:
    patterns = (
        br'(?:location(?:\.href)?|url)\s*=\s*["\']([^"\']+)',
        br'URL=([^"\' >]+)',
    )
    for pattern in patterns:
        match = re.search(pattern, body, re.IGNORECASE)
        if match:
            return match.group(1).decode("ascii", errors="replace")
    return None


def form(serial: str) -> bytes:
    return urllib.parse.urlencode(
        {"submit_flag": "match_sn", "serial_num": serial}
    ).encode("ascii")


def answer_form(answer1: str, answer2: str) -> bytes:
    return urllib.parse.urlencode(
        {
            "submit_flag": "security_question",
            "hidden_answer1": answer1,
            "hidden_answer2": answer2,
        }
    ).encode("ascii")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "--port",
        type=int,
        default=PORT,
        help=f"loopback lab-forward port (default: {PORT})",
    )
    args = parser.parse_args()
    if not healthy(args.port):
        print("baseline_failed")
        return 2

    serial_path = recovery_path(args.port)
    serial_status, serial_response = request(
        "POST", serial_path, form("FRIDAYLAB0001"), port=args.port
    )
    serial_redirect = redirect_target(serial_response)
    print(
        "valid-serial "
        f"http={serial_status} response_bytes={len(serial_response)} "
        f"redirect={serial_redirect!r} alive={healthy(args.port)}"
    )

    question_path, _ = page_recovery_path(
        "/securityquestions.cgi", args.port
    )
    encoded_answer1 = base64.b64encode(b"friday-answer-one").decode("ascii")
    encoded_answer2 = base64.b64encode(b"friday-answer-two").decode("ascii")
    answer_status, answer_response = request(
        "POST",
        question_path,
        answer_form(encoded_answer1, encoded_answer2),
        port=args.port,
    )
    answer_redirect = redirect_target(answer_response)
    print(
        "valid-answers "
        f"http={answer_status} response_bytes={len(answer_response)} "
        f"redirect={answer_redirect!r} alive={healthy(args.port)}"
    )

    cases = [
        ("normal-invalid", "WRONGSERIAL01"),
        ("metacharacters", "FRIDAY;|&$()`LAB"),
        ("length-128", "A" * 128),
        ("length-1024", "A" * 1024),
        ("length-8192", "A" * 8192),
        ("length-65536", "A" * 65536),
    ]
    for name, serial in cases:
        try:
            path = recovery_path(args.port)
            status, response = request(
                "POST", path, form(serial), port=args.port
            )
            outcome = f"http={status} response_bytes={len(response)}"
        except (OSError, TimeoutError, http.client.HTTPException) as error:
            outcome = f"request_error={error}"
        time.sleep(0.2)
        alive = healthy(args.port)
        print(
            f"{name} serial_bytes={len(serial)} {outcome} alive={alive}"
        )
        if not alive:
            print(f"crash_candidate={name}")
            return 1
    answer_cases = [
        ("answers-normal-invalid", "RlJJREFZ"),
        ("answers-metacharacters", "O3wkKClgJg=="),
        ("answers-length-1024", "A" * 1024),
        ("answers-length-8192", "A" * 8192),
        ("answers-length-65536", "A" * 65536),
    ]
    for name, answer in answer_cases:
        try:
            status, response = request(
                "POST",
                "/recover.cgi?/securityquestions.cgi%20timestamp=",
                answer_form(answer, answer),
                port=args.port,
            )
            outcome = f"http={status} response_bytes={len(response)}"
        except (OSError, TimeoutError, http.client.HTTPException) as error:
            outcome = f"request_error={error}"
        time.sleep(0.2)
        alive = healthy(args.port)
        print(
            f"{name} answer_bytes={len(answer)} {outcome} alive={alive}"
        )
        if not alive:
            print(f"crash_candidate={name}")
            return 1
    print("result=no-observable-recovery-parser-dos")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
