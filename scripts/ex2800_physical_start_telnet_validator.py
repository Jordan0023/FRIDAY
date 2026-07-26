#!/usr/bin/env python3
"""Bounded physical-device validator for the mini_httpd start_telnet route.

The validator:
  * accepts only loopback, RFC1918, or IPv6 private/link-local targets;
  * requires an explicit acknowledgement because the route changes the
    device's runtime inetd configuration until reboot;
  * sends one fixed HTTP request;
  * checks whether TCP/23 changes from closed to reachable;
  * does not attempt authentication or execute commands.
"""

import argparse
import ipaddress
import socket
import ssl
import sys
import time
import urllib.parse


ACK = "I_OWN_THIS_DEVICE_AND_WILL_REBOOT_IT"


def private_target(value: str) -> tuple[str, str]:
    try:
        infos = socket.getaddrinfo(value, None, type=socket.SOCK_STREAM)
    except socket.gaierror as exc:
        raise argparse.ArgumentTypeError(f"cannot resolve target: {exc}") from exc

    addresses = []
    for info in infos:
        address = info[4][0].split("%", 1)[0]
        ip = ipaddress.ip_address(address)
        if not (ip.is_private or ip.is_loopback or ip.is_link_local):
            raise argparse.ArgumentTypeError(
                f"{address} is not a private, loopback, or link-local address"
            )
        addresses.append(address)
    if not addresses:
        raise argparse.ArgumentTypeError("target resolved to no usable address")
    return value, addresses[0]


def tcp_reachable(host: str, port: int, timeout: float = 1.5) -> bool:
    try:
        with socket.create_connection((host, port), timeout=timeout):
            return True
    except OSError:
        return False


def fixed_http_trigger(host: str, port: int, use_tls: bool = False) -> bytes:
    request = (
        b"GET /start_telnet HTTP/1.0\r\n"
        + f"Host: {host}\r\n".encode("ascii", "strict")
        + b"Connection: close\r\n\r\n"
    )
    with socket.create_connection((host, port), timeout=3) as raw_connection:
        if use_tls:
            # Embedded devices commonly use a self-signed management
            # certificate. This connection is restricted to the already
            # validated private target and is used only for this fixed probe.
            context = ssl.SSLContext(ssl.PROTOCOL_TLS_CLIENT)
            context.check_hostname = False
            context.verify_mode = ssl.CERT_NONE
            connection = context.wrap_socket(raw_connection, server_hostname=host)
        else:
            connection = raw_connection
        connection.settimeout(3)
        connection.sendall(request)
        response = b""
        while len(response) < 4096:
            try:
                block = connection.recv(4096 - len(response))
            except socket.timeout:
                break
            if not block:
                break
            response += block
    return response


def status_line(response: bytes) -> str:
    first = response.splitlines()[0] if response else b""
    return first.decode("ascii", "replace")


def response_header(response: bytes, name: str) -> str:
    wanted = name.lower().encode("ascii")
    for line in response.split(b"\r\n")[1:]:
        if b":" not in line:
            continue
        key, value = line.split(b":", 1)
        if key.strip().lower() == wanted:
            return value.strip().decode("ascii", "replace")
    return ""


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Confirm the fixed-action start_telnet route without logging in"
    )
    parser.add_argument("--target", required=True, type=private_target)
    parser.add_argument("--http-port", type=int, default=80)
    parser.add_argument("--https-port", type=int, default=443)
    parser.add_argument("--telnet-port", type=int, default=23)
    parser.add_argument(
        "--transport",
        choices=("auto", "http", "https"),
        default="auto",
        help="auto retries a same-target HTTP redirect over HTTPS",
    )
    parser.add_argument(
        "--acknowledge",
        required=True,
        help=f"must be exactly: {ACK}",
    )
    parser.add_argument("--wait-seconds", type=float, default=3.0)
    args = parser.parse_args()

    if args.acknowledge != ACK:
        parser.error(f"--acknowledge must be exactly {ACK}")
    if not (
        1 <= args.http_port <= 65535
        and 1 <= args.https_port <= 65535
        and 1 <= args.telnet_port <= 65535
    ):
        parser.error("ports must be between 1 and 65535")
    if not (0 <= args.wait_seconds <= 15):
        parser.error("--wait-seconds must be between 0 and 15")

    original, resolved = args.target
    print(f"target={original}")
    print(f"resolved_private_address={resolved}")
    before = tcp_reachable(resolved, args.telnet_port)
    print(f"telnet_reachable_before={str(before).lower()}")

    if args.transport == "https":
        try:
            response = fixed_http_trigger(resolved, args.https_port, use_tls=True)
        except OSError as exc:
            print(f"tested_transport=https:{args.https_port}")
            print(f"management_connection_error={exc!r}")
            print("result=not_tested: HTTPS management transport is unreachable")
            return 3
        print(f"tested_transport=https:{args.https_port}")
        print(f"https_status_line={status_line(response)!r}")
    else:
        try:
            response = fixed_http_trigger(resolved, args.http_port)
        except OSError as exc:
            print(f"tested_transport=http:{args.http_port}")
            print(f"management_connection_error={exc!r}")
            print("result=not_tested: HTTP management transport is unreachable")
            return 3
        print(f"tested_transport=http:{args.http_port}")
        print(f"http_status_line={status_line(response)!r}")
        location = response_header(response, "location")
        print(f"http_location={location!r}")
        code = status_line(response).split(" ", 2)
        redirect = len(code) > 1 and code[1] in {"301", "302", "303", "307", "308"}
        if args.transport == "auto" and redirect and location:
            parsed = urllib.parse.urlsplit(location)
            redirect_host = parsed.hostname
            if parsed.scheme.lower() == "https" and (
                redirect_host is None
                or redirect_host == original
                or redirect_host == resolved
            ):
                tls_port = parsed.port or args.https_port
                if tls_port != args.https_port:
                    raise RuntimeError(
                        "redirect selected a non-configured HTTPS port; "
                        "rerun with --https-port matching that private service"
                    )
                try:
                    response = fixed_http_trigger(resolved, tls_port, use_tls=True)
                except OSError as exc:
                    print(f"tested_redirect_transport=https:{tls_port}")
                    print(f"management_connection_error={exc!r}")
                    print(
                        "result=not_tested: redirected HTTPS transport is unreachable"
                    )
                    return 3
                print(f"tested_redirect_transport=https:{tls_port}")
                print(f"https_status_line={status_line(response)!r}")
            else:
                print(
                    "same_target_https_redirect_followed=false",
                    file=sys.stderr,
                )
    time.sleep(args.wait_seconds)

    after = tcp_reachable(resolved, args.telnet_port)
    print(f"telnet_reachable_after={str(after).lower()}")
    confirmed = (not before) and after
    print(f"start_telnet_effect_confirmed={str(confirmed).lower()}")
    print("recovery_required=reboot_device")

    if before:
        print(
            "result=indeterminate: TCP/23 was already reachable before the request",
            file=sys.stderr,
        )
        return 2
    if not after:
        print(
            "result=not_confirmed: TCP/23 did not become reachable",
            file=sys.stderr,
        )
        return 1
    print("result=confirmed: TCP/23 changed from closed to reachable")
    return 0


if __name__ == "__main__":
    sys.exit(main())
