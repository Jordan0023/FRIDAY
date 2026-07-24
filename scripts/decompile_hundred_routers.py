#!/usr/bin/env python3
"""Resumable, receipt-driven exhaustive ELF decompilation for the 74-router set."""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import subprocess
import time
from concurrent.futures import ThreadPoolExecutor, as_completed
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DEFAULT_CAMPAIGN = ROOT / "router-agent-results/20260722T235859Z-seventy-four-router-hunt"
DEFAULT_OUTPUT = ROOT / "router-agent-results/20260722T235859Z-seventy-four-router-exhaustive-decompile"
EOL_PRODUCTS_PATH = ROOT / "site/data/eol-products.json"
GHIDRA = Path("/home/jordan/Tools/ghidra_12.1.2_PUBLIC/support/analyzeHeadless")
SECURITY_SCHEMA = 4
COMPATIBLE_SECURITY_SCHEMAS = {3, SECURITY_SCHEMA}


def receipt_status(data: dict, evidence: Path) -> str | None:
    """Return reusable receipt coverage without discarding successful functions."""
    if not evidence.is_file() or data.get("security_schema") not in COMPATIBLE_SECURITY_SCHEMAS:
        return None
    if data.get("functions_attempted") != data.get("functions_discovered"):
        return None
    failed = int(data.get("functions_failed", 0) or 0)
    if data.get("security_schema") == 3 and failed:
        return None
    return "complete" if failed == 0 else "partial"


def elf_machine(path: Path) -> int | None:
    try:
        header = path.open("rb").read(20)
    except OSError:
        return None
    if len(header) < 20 or header[:4] != b"\x7fELF" or header[5] not in (1, 2):
        return None
    return int.from_bytes(header[18:20], "little" if header[5] == 1 else "big")


def is_elf(path: Path) -> bool:
    """Return true only for ELF files that declare a processor architecture."""
    machine = elf_machine(path)
    return machine is not None and machine != 0


def file_id(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as handle:
        for chunk in iter(lambda: handle.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def decompile(job: dict, output: Path, timeout: int) -> dict:
    binary = Path(job["binary"])
    receipt = output / "receipts" / job["router_sha"] / f"{job['id']}.json"
    evidence = output / "evidence" / job["router_sha"] / f"{job['id']}.jsonl"
    log = output / "logs" / job["router_sha"] / f"{job['id']}.log"
    receipt.parent.mkdir(parents=True, exist_ok=True)
    evidence.parent.mkdir(parents=True, exist_ok=True)
    log.parent.mkdir(parents=True, exist_ok=True)
    if receipt.is_file():
        try:
            data = json.loads(receipt.read_text())
            status = receipt_status(data, evidence)
            if status:
                return {**job, "status": status, "receipt": str(receipt),
                        "evidence": str(evidence), "candidate_functions": data.get("candidate_functions", 0),
                        "functions_failed": data.get("functions_failed", 0)}
        except (OSError, json.JSONDecodeError):
            pass
    project = f"exhaustive_{job['router_sha'][:8]}_{job['id']}_{os.getpid()}_{time.time_ns()}"
    env = os.environ.copy()
    runtime = (output / "runtime").resolve()
    env.update(XDG_CONFIG_HOME=str(runtime / "config"), XDG_CACHE_HOME=str(runtime / "cache"), XDG_STATE_HOME=str(runtime / "state"))
    cmd = [str(GHIDRA), str(output / "projects"), project, "-import", str(binary),
           "-analysisTimeoutPerFile", str(timeout), "-scriptPath", str(ROOT / "ghidra_scripts"),
           "-postScript", "FridayDecompileReceipt.java", str(receipt), str(evidence), "-deleteProject"]
    try:
        result = subprocess.run(cmd, text=True, capture_output=True, timeout=timeout + 180, env=env)
        log.write_text(result.stdout + "\n" + result.stderr, errors="replace")
        data = json.loads(receipt.read_text()) if receipt.is_file() else {}
        status = receipt_status(data, evidence) if result.returncode == 0 else None
        return {**job, "status": status, "returncode": result.returncode, "receipt": str(receipt),
                "evidence": str(evidence), "candidate_functions": data.get("candidate_functions", 0),
                "functions_failed": data.get("functions_failed", 0), "log": str(log)} if status else {
                    **job, "status": "failed", "returncode": result.returncode, "receipt": str(receipt), "log": str(log)}
    except subprocess.TimeoutExpired as exc:
        stdout = exc.stdout.decode(errors="replace") if isinstance(exc.stdout, bytes) else (exc.stdout or "")
        stderr = exc.stderr.decode(errors="replace") if isinstance(exc.stderr, bytes) else (exc.stderr or "")
        log.write_text(stdout + "\n" + stderr, errors="replace")
        return {**job, "status": "timeout", "receipt": str(receipt), "log": str(log)}


def write_summary(output: Path, routers: list[dict], results: list[dict]) -> None:
    counts = {key: sum(x.get("status") == key for x in results) for key in ("complete", "partial", "failed", "timeout")}
    unique = len({item["content_sha256"] for router in routers for item in router["elf_files"]})
    payload = {"updated_at": datetime.now(timezone.utc).isoformat(), "routers": len(routers),
               "routers_with_elf": sum(bool(x["elf_files"]) for x in routers),
               "routers_without_elf": sum(not x["elf_files"] for x in routers),
               "binary_instances_discovered": sum(len(x["elf_files"]) for x in routers),
               "unique_binaries_discovered": unique,
               "unsupported_elf_like_instances": sum(len(x.get("unsupported_elf_like_files", [])) for x in routers),
               "counts": {**counts, "security_analyzed": sum(
                   x.get("status") in {"complete", "partial"} and bool(x.get("evidence"))
                   for x in results
               ),
                          "unresolved_functions": sum(int(x.get("functions_failed", 0) or 0) for x in results),
                          "candidate_functions": sum(x.get("candidate_functions", 0) for x in results)},
               "processed": len(results) == unique and not counts["failed"] and not counts["timeout"],
               "complete": len(results) == unique and not counts["partial"] and not counts["failed"] and not counts["timeout"],
               "router_inventory": routers, "results": sorted(results, key=lambda x: (x["router_sha"], x["binary"]))}
    (output / "summary.json").write_text(json.dumps(payload, indent=2) + "\n")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--campaign", type=Path, default=DEFAULT_CAMPAIGN)
    parser.add_argument("--output", type=Path, default=DEFAULT_OUTPUT)
    parser.add_argument("--workers", type=int, default=3)
    parser.add_argument("--timeout", type=int, default=1800)
    parser.add_argument("--inventory-only", action="store_true")
    parser.add_argument("--rootfs", type=Path,
                        help="Analyze one already-extracted root filesystem instead of a campaign.")
    parser.add_argument("--product", help="Product name used with --rootfs.")
    parser.add_argument("--router-sha", help="Firmware SHA-256 used with --rootfs.")
    args = parser.parse_args()
    if args.rootfs:
        if not args.product or not args.router_sha:
            parser.error("--rootfs requires --product and --router-sha")
        rootfs = args.rootfs.resolve()
        if not rootfs.is_dir():
            parser.error(f"--rootfs is not a directory: {rootfs}")
        selected = [{"product": args.product, "sha256": args.router_sha,
                     "_extracted_root": str(rootfs)}]
    else:
        selected = json.loads((args.campaign / "selection.json").read_text())
        eol_products = set(json.loads(EOL_PRODUCTS_PATH.read_text()).get("products", []))
        blocked = sorted({record.get("product", "") for record in selected} & eol_products)
        if blocked:
            raise SystemExit("Campaign contains EOL routers: " + ", ".join(blocked))
    args.output.mkdir(parents=True, exist_ok=True)
    (args.output / "projects").mkdir(parents=True, exist_ok=True)
    routers, jobs_by_id = [], {}
    for record in selected:
        sha = record["sha256"]
        extracted = Path(record["_extracted_root"]) if record.get("_extracted_root") else (
            ROOT / "known_firmware/extracted" / sha[:16])
        candidates = sorted(p for p in extracted.rglob("*") if p.is_file() and elf_machine(p) is not None) if extracted.is_dir() else []
        files = [str(p) for p in candidates if is_elf(p)]
        unsupported = [str(p) for p in candidates if elf_machine(p) == 0]
        inventory_files = []
        for path_text in files:
            identifier = file_id(Path(path_text))
            inventory_files.append({"path": path_text, "content_sha256": identifier})
            job = jobs_by_id.setdefault(identifier, {"router": record["product"], "router_sha": sha,
                                                       "binary": path_text, "id": identifier, "instances": []})
            job["instances"].append({"router": record["product"], "router_sha": sha, "binary": path_text})
        routers.append({"product": record["product"], "sha256": sha, "extraction_exists": extracted.is_dir(),
                        "elf_files": inventory_files, "unsupported_elf_like_files": unsupported})
    jobs = list(jobs_by_id.values())
    (args.output / "inventory.json").write_text(json.dumps(routers, indent=2) + "\n")
    results = []
    write_summary(args.output, routers, results)
    if args.inventory_only:
        print(f"routers={len(routers)} unique_elf_binaries={len(jobs)} elf_instances={sum(len(x['elf_files']) for x in routers)}")
        return 0
    with ThreadPoolExecutor(max_workers=args.workers) as pool:
        futures = [pool.submit(decompile, job, args.output, args.timeout) for job in jobs]
        for index, future in enumerate(as_completed(futures), 1):
            result = future.result()
            results.append(result)
            if index % 10 == 0 or result["status"] != "complete": write_summary(args.output, routers, results)
            print(f"[{index}/{len(jobs)}] {result['status']}: {result['router']} :: {Path(result['binary']).name}", flush=True)
    write_summary(args.output, routers, results)
    return 0 if json.loads((args.output / "summary.json").read_text())["complete"] else 1


if __name__ == "__main__":
    raise SystemExit(main())
