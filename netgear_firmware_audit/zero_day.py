from __future__ import annotations

import json
import re
import subprocess
from dataclasses import asdict, dataclass
from pathlib import Path

from .advanced_analysis import (
    archive_test_cases,
    auth_test_matrix,
    build_fuzz_seeds,
    build_runtime_launch_plan,
    confirmation_policy,
    correlate_flows,
    dynamic_sink_spec,
    profile_runtime,
    safe_validation_recipes,
)


@dataclass(frozen=True)
class KnownVulnerability:
    id: str
    product_pattern: str
    affected_versions: tuple[str, ...]
    fixed_in: str | None
    route: str
    parameter: str
    vulnerability_class: str
    auth: str
    references: tuple[str, ...]


@dataclass
class KnownCoverage:
    vulnerability: KnownVulnerability
    applicability: str
    route_present: bool
    parameter_present: bool
    notes: str


@dataclass
class RouteCandidate:
    route: str
    source: str
    parameters: list[str]
    matched_keywords: list[str]
    score: int
    evidence_level: str
    auth_class: str
    exposure: str
    impact_class: str
    disposition: str
    evidence: list[str]
    recommended_checks: list[str]


@dataclass
class ServiceSurface:
    service: str
    source: str
    protocol: str
    exposure: str
    auth_class: str
    risk: str
    evidence: list[str]


@dataclass
class ZeroDayTriage:
    rootfs: str
    known_coverage: list[KnownCoverage]
    candidates: list[RouteCandidate]
    rejected_candidates: list[RouteCandidate]
    service_surface: list[ServiceSurface]
    sink_summary: dict[str, int]
    config_writers: list[str]
    runtime_profile: dict
    correlated_flows: list[dict]
    ghidra_evidence: list[dict[str, str]]
    validation_recipes: list[dict]
    runtime_launch_plan: dict
    auth_test_matrix: list[dict]
    fuzz_seeds: list[dict]
    archive_test_cases: list[dict]
    dynamic_sink_spec: list[dict]
    confirmation_policy: dict
    notes: list[str]

    def to_json(self) -> str:
        return json.dumps(asdict(self), indent=2, sort_keys=True)


KNOWN_VULNERABILITIES: tuple[KnownVulnerability, ...] = (
    KnownVulnerability(
        id="CVE-2016-6277",
        product_pattern=r"\bR7000\b",
        affected_versions=("1.0.7.2",),
        fixed_in=None,
        route="/cgi-bin/;COMMAND",
        parameter="path",
        vulnerability_class="unauthenticated command injection",
        auth="none",
        references=("https://www.kb.cert.org/vuls/id/582384",),
    ),
    KnownVulnerability(
        id="CVE-2024-35520",
        product_pattern=r"\bR7000\b",
        affected_versions=("1.0.11.136",),
        fixed_in=None,
        route="RMT_invite.cgi",
        parameter="device_name2",
        vulnerability_class="command injection",
        auth="post-auth",
        references=("https://nvd.nist.gov/vuln/detail/CVE-2024-35520",),
    ),
    KnownVulnerability(
        id="NETGEAR-PSV-2023-0154",
        product_pattern=r"\bR7000\b",
        affected_versions=(),
        fixed_in="1.0.11.216",
        route="unknown",
        parameter="unknown",
        vulnerability_class="post-authentication command injection",
        auth="admin",
        references=(
            "https://kb.netgear.com/000066027/Security-Advisory-for-Post-Authentication-Command-Injection-on-the-R7000-PSV-2023-0154",
        ),
    ),
    KnownVulnerability(
        id="NETGEAR-PSV-2024-0013",
        product_pattern=r"\bR7000\b",
        affected_versions=(),
        fixed_in="1.0.11.216",
        route="unknown",
        parameter="unknown",
        vulnerability_class="post-authentication command injection",
        auth="admin",
        references=(
            "https://kb.netgear.com/000066083/Security-Advisory-for-Post-Authentication-Command-Injection-on-R7000-PSV-2024-0013",
        ),
    ),
)


ROUTE_RE = re.compile(
    r"""(?ix)
    (?:action|href|src)\s*=\s*["']?([^"'\s>]*?(?:cgi|cgi-bin|debug|openvpn|vpn|pppoe|wan|usb|readycloud)[^"'\s>]*)|
    \b([A-Za-z0-9_.-]+\.cgi)\b
    """
)
PARAM_RE = re.compile(r"""(?ix)\b(?:name|id)\s*=\s*["']?([A-Za-z0-9_.:-]{2,80})""")
SINK_PATTERNS = {
    "system": re.compile(r"\b(?:system|doSystem)\s*\(|/bin/sh|/bin/ash|\bsh -c\b", re.I),
    "popen": re.compile(r"\bpopen\s*\(", re.I),
    "exec": re.compile(r"\bexec(?:l|le|lp|v|ve|vp)?\s*\(", re.I),
    "unsafe_copy": re.compile(r"\b(?:strcpy|strcat|sprintf|gets|scanf)\b"),
    "file_write": re.compile(r"\b(?:fopen|fprintf|fputs|write)\b"),
}
RISK_KEYWORDS = {
    "command": 5,
    "debug": 4,
    "readycloud": 4,
    "vpn": 4,
    "openvpn": 4,
    "upload": 4,
    "upgrade": 4,
    "fw": 3,
    "wan": 3,
    "gateway": 3,
    "dns": 3,
    "ddns": 3,
    "ntp": 3,
    "ping": 3,
    "traceroute": 3,
    "usb": 3,
    "share": 3,
    "samba": 3,
    "pppoe": 3,
    "telnet": 3,
    "remote": 2,
    "hidden": 2,
}
RISK_PARAMS = {
    "cmd",
    "command",
    "host",
    "hostname",
    "ip",
    "addr",
    "address",
    "gateway",
    "wan_gateway",
    "apmode_gateway",
    "dns",
    "ddns",
    "ntp_server",
    "user_ntp_server",
    "device_name",
    "device_name2",
    "openvpn_push1",
    "path",
    "filename",
    "share_name",
}
AUTH_MARKERS = re.compile(r"\b(?:auth|authorize|login|logout|password|passwd|session|token|csrf|cookie)\b", re.I)
PUBLIC_MARKERS = re.compile(r"\b(?:no[_ -]?auth|unauth|public|pre[_ -]?auth|auth[_ -]?skip|whitelist|setup|wizard|onboard)\b", re.I)
ADMIN_MARKERS = re.compile(r"\b(?:admin|administrator|management|apply|upgrade|upload|backup|restore)\b", re.I)
MUTATING_MARKERS = re.compile(r"\b(?:apply|set|add|delete|remove|upload|upgrade|restore|reboot|restart|enable|disable)\b", re.I)
SERVICE_NAMES = {
    "upnp": ("udp", "lan", "none", "high"),
    "miniupnpd": ("udp", "lan", "none", "high"),
    "ssdp": ("udp", "lan", "none", "high"),
    "dnsmasq": ("udp/tcp", "lan", "none", "high"),
    "udhcpd": ("udp", "lan", "none", "high"),
    "dhcpd": ("udp", "lan", "none", "high"),
    "smbd": ("tcp", "lan", "unknown", "medium"),
    "samba": ("tcp", "lan", "unknown", "medium"),
    "dropbear": ("tcp", "lan", "required", "low"),
    "telnetd": ("tcp", "lan", "unknown", "high"),
    "ftpd": ("tcp", "lan", "unknown", "medium"),
    "cloud": ("tcp", "outbound", "device", "high"),
    "mesh": ("unknown", "lan/wireless", "device", "high"),
}
CONFIG_MARKERS = (
    "openvpn",
    "server.conf",
    "client.conf",
    "dnsmasq.conf",
    "smb.conf",
    "iptables",
    "firewall",
    "crontab",
    "udhcpd.conf",
    "lighttpd.conf",
)


def analyze_zero_day_surface(
    rootfs: Path,
    product: str = "",
    version: str | None = None,
    ghidra_evidence: list[dict[str, str]] | None = None,
) -> ZeroDayTriage:
    rootfs = rootfs.resolve()
    files = [path for path in rootfs.rglob("*") if path.is_file() and not path.is_symlink()] if rootfs.exists() else []
    sample_files = _sample_files(files)
    strings_by_file = _collect_strings(sample_files)
    routes = _discover_routes(rootfs, sample_files, strings_by_file)
    all_params = _discover_parameters(rootfs, sample_files)
    sink_summary = _summarize_sinks(strings_by_file)
    config_writers = _find_config_writers(strings_by_file)
    known = _known_coverage(product, version, routes, all_params)
    candidates, rejected = _score_routes(rootfs, routes, all_params, strings_by_file, ghidra_evidence or [])
    services = _discover_services(rootfs, strings_by_file)
    routes_by_source = _routes_by_source(strings_by_file)
    flows = correlate_flows(rootfs, strings_by_file, routes_by_source)
    profile = profile_runtime(rootfs, product)
    runtime_plan = build_runtime_launch_plan(rootfs, product)
    notes = [
        "Evidence levels: L0 route/string present, L1 parameters identified, L2 dangerous sink present in firmware, L3 route/parameter-to-sink flow should be proven with decompiler, L4 filter bypass plausible, L5 live PoC confirmed.",
        "Only routes with a plausible low-privilege boundary and route-local sink evidence are promoted. Global firmware sink counts never raise route evidence.",
        "Authentication labels inferred from strings are hypotheses until dispatcher control flow or a live request confirms them.",
        "This triage increases zero-day coverage but does not replace route-specific reverse engineering or live emulation.",
    ]
    return ZeroDayTriage(
        rootfs=str(rootfs),
        known_coverage=known,
        candidates=candidates,
        rejected_candidates=rejected,
        service_surface=services,
        sink_summary=sink_summary,
        config_writers=config_writers[:50],
        runtime_profile=asdict(profile),
        correlated_flows=[asdict(flow) for flow in flows[:100]],
        ghidra_evidence=(ghidra_evidence or [])[:500],
        validation_recipes=[asdict(recipe) for recipe in safe_validation_recipes()],
        runtime_launch_plan=asdict(runtime_plan),
        auth_test_matrix=[asdict(item) for item in auth_test_matrix()],
        fuzz_seeds=[asdict(item) for item in build_fuzz_seeds(list(routes), all_params)],
        archive_test_cases=[asdict(item) for item in archive_test_cases()],
        dynamic_sink_spec=dynamic_sink_spec(),
        confirmation_policy=confirmation_policy(),
        notes=notes,
    )


def render_zero_day_markdown(triage: ZeroDayTriage) -> str:
    lines = [
        "## Zero-day Triage",
        "",
        "This section separates known-vulnerability coverage from new candidate hunting. Statuses here are leads until a route-specific data flow or live PoC confirms exploitability.",
        "",
        "### Known Vulnerability Coverage",
        "",
    ]
    if not triage.known_coverage:
        lines.append("No known-vulnerability catalog entries matched this product name.")
    for item in triage.known_coverage:
        vuln = item.vulnerability
        lines.extend(
            [
                f"#### {vuln.id}",
                "",
                f"- Class: {vuln.vulnerability_class}",
                f"- Applicability: {item.applicability}",
                f"- Route present: {'yes' if item.route_present else 'no'} (`{vuln.route}`)",
                f"- Parameter present: {'yes' if item.parameter_present else 'no'} (`{vuln.parameter}`)",
                f"- Auth/precondition: {vuln.auth}",
                f"- Notes: {item.notes}",
                f"- References: {', '.join(vuln.references)}",
                "",
            ]
        )
    lines.extend(["### High-priority New Candidates", ""])
    if not triage.candidates:
        lines.append("No route candidates were identified.")
    for candidate in triage.candidates[:30]:
        params = ", ".join(candidate.parameters[:12]) if candidate.parameters else "none discovered"
        keywords = ", ".join(candidate.matched_keywords) if candidate.matched_keywords else "none"
        checks = "; ".join(candidate.recommended_checks)
        lines.extend(
            [
                f"#### `{candidate.route}`",
                "",
                f"- Score: {candidate.score}",
                f"- Evidence level: {candidate.evidence_level}",
                f"- Authentication: {candidate.auth_class}",
                f"- Exposure: {candidate.exposure}",
                f"- Potential impact: {candidate.impact_class}",
                f"- Disposition: {candidate.disposition}",
                f"- Source: {candidate.source}",
                f"- Parameters: {params}",
                f"- Matched risk keywords: {keywords}",
                f"- Evidence: {'; '.join(candidate.evidence)}",
                f"- Next checks: {checks}",
                "",
            ]
        )
    lines.extend(["### Rejected or Deprioritized Routes", ""])
    if triage.rejected_candidates:
        for candidate in triage.rejected_candidates[:30]:
            lines.append(
                f"- `{candidate.route}`: {candidate.disposition}; auth={candidate.auth_class}; "
                f"evidence={candidate.evidence_level}; score={candidate.score}"
            )
    else:
        lines.append("No routes were explicitly rejected by the impact gate.")
    lines.extend(["", "### Non-HTTP Service Surface", ""])
    if triage.service_surface:
        for service in triage.service_surface[:40]:
            lines.append(
                f"- `{service.service}` ({service.protocol}, {service.exposure}): auth={service.auth_class}, "
                f"risk={service.risk}; source=`{service.source}`; evidence={'; '.join(service.evidence)}"
            )
    else:
        lines.append("No prioritized non-HTTP services were identified.")
    lines.extend(["", "### Sink Summary", ""])
    for name, count in sorted(triage.sink_summary.items()):
        lines.append(f"- {name}: {count}")
    lines.extend(["", "### Config Writer Leads", ""])
    if triage.config_writers:
        lines.extend(f"- `{item}`" for item in triage.config_writers[:30])
    else:
        lines.append("No config-writer markers found in sampled strings.")
    lines.extend(["", "### Handler-level Correlated Flows", ""])
    if triage.correlated_flows:
        for flow in triage.correlated_flows[:20]:
            lines.append(f"- `{flow['source_file']}`: {flow['confidence']}, score {flow['score']}; sources={', '.join(flow['sources'])}; sinks={', '.join(flow['sinks'])}")
    else:
        lines.append("No source and dangerous sink were co-located in the same sampled handler or binary.")
    lines.extend(["", "### Ghidra Function-local Evidence", ""])
    if triage.ghidra_evidence:
        for item in triage.ghidra_evidence[:30]:
            lines.append(
                f"- `{item.get('binary', 'unknown')}:{item.get('function', 'unknown')}` "
                f"at `{item.get('address', 'unknown')}`: route `{item.get('route', 'unknown')}`, "
                f"sink `{item.get('sink', 'unknown')}`"
            )
    else:
        lines.append("No function-local route/sink pairs were emitted by Ghidra.")
    lines.extend(["", "### Runtime Profile", ""])
    profile = triage.runtime_profile
    lines.extend([
        f"- Vendor profile: {profile['vendor']}",
        f"- Web stack: {', '.join(profile['web_stack']) or 'not identified'}",
        f"- State backends: {', '.join(profile['state_backends']) or 'not identified'}",
        f"- Architectures: {', '.join(profile['architectures']) or 'not identified'}",
        f"- Executables/scripts discovered: {profile['executable_count']}",
    ])
    lines.extend(["", "### Dynamic Validation Plan", ""])
    plan = triage.runtime_launch_plan
    lines.append(f"- Isolation: {', '.join(plan['isolation'])}")
    lines.append(f"- Startup candidates: {', '.join(plan['startup_candidates'][:8]) or 'none identified'}")
    lines.append(f"- Listener candidates: {', '.join(plan['listener_candidates'][:8]) or 'none identified'}")
    lines.append(f"- Runtime requirements discovered: {len(plan['requirements'])}")
    lines.append(f"- Authentication cases: {', '.join(item['name'] for item in triage.auth_test_matrix)}")
    lines.append(f"- Structured fuzz seeds: {len(triage.fuzz_seeds)}")
    lines.append(f"- Archive validation cases: {len(triage.archive_test_cases)}")
    lines.extend(["", "### Confirmation Policy", ""])
    for key, value in triage.confirmation_policy.items():
        lines.append(f"- {key}: {value}")
    lines.extend(["", "### Triage Notes", ""])
    lines.extend(f"- {note}" for note in triage.notes)
    lines.append("")
    return "\n".join(lines)


def _sample_files(files: list[Path]) -> list[Path]:
    priority = []
    rest = []
    for path in files:
        rel = "/".join(path.parts[-4:]).lower()
        if any(key in rel for key in ("www", "cgi", "httpd", "net-cgi", "boa", "lighttpd", "rc", "init.d")):
            priority.append(path)
        else:
            rest.append(path)
    return (priority + rest)[:1500]


def _collect_strings(files: list[Path]) -> dict[str, list[str]]:
    strings_by_file: dict[str, list[str]] = {}
    strings_bin = _which_strings()
    for path in files:
        try:
            if path.stat().st_size > 25 * 1024 * 1024:
                continue
        except OSError:
            continue
        text = ""
        if path.suffix.lower() in {".htm", ".html", ".js", ".asp", ".cgi", ".sh", ".conf", ".xml"}:
            try:
                text = path.read_text(encoding="utf-8", errors="ignore")
            except OSError:
                continue
        elif strings_bin:
            try:
                result = subprocess.run([strings_bin, "-a", str(path)], text=True, capture_output=True, timeout=10)
            except (OSError, subprocess.TimeoutExpired):
                continue
            text = result.stdout
        if text:
            strings_by_file[str(path)] = [line.strip() for line in text.splitlines() if len(line.strip()) >= 3][:5000]
    return strings_by_file


def _discover_routes(rootfs: Path, files: list[Path], strings_by_file: dict[str, list[str]]) -> dict[str, str]:
    routes: dict[str, str] = {}
    www = rootfs / "www"
    if www.exists():
        for path in www.rglob("*"):
            if path.is_file() and (path.name.endswith(".cgi") or "cgi-bin" in path.parts):
                routes.setdefault(_normalize_route(path.name), f"file:{path.relative_to(rootfs)}")
    for path in files:
        lines = strings_by_file.get(str(path), [])
        if not lines:
            continue
        source = _short_source(rootfs, path)
        for line in lines[:5000]:
            for match in ROUTE_RE.finditer(line):
                route = match.group(1) or match.group(2)
                if route:
                    routes.setdefault(_normalize_route(route), source)
    return dict(sorted(routes.items()))


def _routes_by_source(strings_by_file: dict[str, list[str]]) -> dict[str, list[str]]:
    result: dict[str, list[str]] = {}
    for source, lines in strings_by_file.items():
        routes = {
            _normalize_route(match.group(1) or match.group(2))
            for line in lines
            for match in ROUTE_RE.finditer(line)
            if match.group(1) or match.group(2)
        }
        if routes:
            result[source] = sorted(routes)
    return result


def _discover_parameters(rootfs: Path, files: list[Path]) -> dict[str, list[str]]:
    params_by_route: dict[str, set[str]] = {}
    for path in files:
        if path.suffix.lower() not in {".htm", ".html", ".js", ".asp", ".cgi"}:
            continue
        try:
            text = path.read_text(encoding="utf-8", errors="ignore")
        except OSError:
            continue
        params = {m.group(1) for m in PARAM_RE.finditer(text)}
        routes = {_normalize_route(m.group(1) or m.group(2)) for m in ROUTE_RE.finditer(text) if (m.group(1) or m.group(2))}
        if not routes and path.name.endswith(".cgi"):
            routes = {_normalize_route(path.name)}
        for route in routes:
            params_by_route.setdefault(route, set()).update(params)
    return {route: sorted(values) for route, values in sorted(params_by_route.items())}


def _summarize_sinks(strings_by_file: dict[str, list[str]]) -> dict[str, int]:
    summary = {name: 0 for name in SINK_PATTERNS}
    for lines in strings_by_file.values():
        text = "\n".join(lines)
        for name, pattern in SINK_PATTERNS.items():
            summary[name] += len(pattern.findall(text))
    return summary


def _find_config_writers(strings_by_file: dict[str, list[str]]) -> list[str]:
    leads: set[str] = set()
    for source, lines in strings_by_file.items():
        for line in lines:
            lower = line.lower()
            if any(marker in lower for marker in CONFIG_MARKERS):
                leads.add(f"{Path(source).name}: {line[:160]}")
    return sorted(leads)


def _known_coverage(
    product: str,
    version: str | None,
    routes: dict[str, str],
    params_by_route: dict[str, list[str]],
) -> list[KnownCoverage]:
    product_text = product or ""
    route_text = "\n".join(routes)
    param_text = "\n".join(param for params in params_by_route.values() for param in params)
    coverage: list[KnownCoverage] = []
    for vuln in KNOWN_VULNERABILITIES:
        if product_text and not re.search(vuln.product_pattern, product_text, re.I):
            continue
        applicability = _version_applicability(version, vuln)
        route_present = vuln.route != "unknown" and vuln.route.lower() in route_text.lower()
        parameter_present = vuln.parameter != "unknown" and vuln.parameter.lower() in param_text.lower()
        notes = "Known entry matched product; use route and parameter evidence to decide whether this exact issue carries over."
        if applicability == "tested version appears newer than listed fixed version":
            notes = "Known issue exists for this product family; tested version appears newer than the listed fixed release, so focus on patch regression or variants."
        coverage.append(KnownCoverage(vuln, applicability, route_present, parameter_present, notes))
    return coverage


def _score_routes(
    rootfs: Path,
    routes: dict[str, str],
    params_by_route: dict[str, list[str]],
    strings_by_file: dict[str, list[str]],
    ghidra_evidence: list[dict[str, str]],
) -> tuple[list[RouteCandidate], list[RouteCandidate]]:
    """Rank routes using only evidence from their owning file or binary.

    A firmware-wide sink count is deliberately not accepted as route evidence.
    This prevents an unrelated utility containing ``system`` from promoting every
    CGI route in the image.
    """
    candidates: list[RouteCandidate] = []
    rejected: list[RouteCandidate] = []
    for route, source in routes.items():
        route_lower = route.lower()
        params = params_by_route.get(route, [])
        matched = [key for key in RISK_KEYWORDS if key in route_lower]
        source_lines = _source_lines(rootfs, source, strings_by_file)
        source_text = "\n".join(_route_context(route, source, source_lines))
        local_sinks = sorted(name for name, pattern in SINK_PATTERNS.items() if pattern.search(source_text))
        decompiled = [
            item for item in ghidra_evidence
            if _normalize_route(item.get("route", "")).lower() == route_lower
        ]
        decompiled_sinks = sorted({item.get("sink", "") for item in decompiled if item.get("sink")})
        local_sinks = sorted(set(local_sinks) | set(decompiled_sinks))
        auth_class, auth_evidence = _classify_auth(route, source_text)
        exposure = _classify_route_exposure(route, source_text)
        score = 5 if route_lower.endswith(".cgi") or "cgi-bin" in route_lower else 0
        score += sum(RISK_KEYWORDS[key] for key in matched)
        risky_params = [param for param in params if param.lower() in RISK_PARAMS or any(key in param.lower() for key in RISK_PARAMS)]
        score += min(len(risky_params) * 3, 12)
        score += min(len(local_sinks) * 5, 20)
        score += {"none": 20, "setup-only": 10, "unknown": 2, "required": -15, "admin": -30}[auth_class]
        score += {"wan/lan": 8, "lan": 5, "unknown": 0}[exposure]
        evidence = [*auth_evidence]
        if risky_params:
            evidence.append(f"risky parameters: {', '.join(risky_params[:8])}")
        if local_sinks:
            evidence.append(f"route-local sinks: {', '.join(local_sinks)}")
        else:
            evidence.append("no route-local dangerous sink found")
        for item in decompiled[:5]:
            evidence.append(
                f"Ghidra function {item.get('function', 'unknown')} at {item.get('address', 'unknown')} "
                f"contains route and {item.get('sink', 'sink')}"
            )
        level = "L3" if local_sinks and risky_params else ("L2" if local_sinks else ("L1" if params else "L0"))
        mutating = bool(MUTATING_MARKERS.search(route_lower))
        impact_class = _potential_impact(local_sinks, risky_params, mutating)
        if auth_class in {"admin", "required"}:
            disposition = "deprioritized: authenticated administrator or privileged session required"
        elif not local_sinks:
            disposition = "rejected: route is not correlated with a dangerous sink"
        elif not risky_params and not mutating:
            disposition = "deprioritized: sink exists but no attacker-controlled parameter is identified"
        elif auth_class == "unknown":
            disposition = "candidate: prove authentication boundary before deeper exploitation work"
        else:
            disposition = "candidate: plausible low-privilege path with route-local sink evidence"
        checks = [
            "confirm dispatcher authentication control flow",
            "trace each risky parameter into command/file/memory sinks",
        ]
        if local_sinks:
            checks.append("prove or reject parameter-to-system/popen/exec flow")
        if any(key in route_lower for key in ("vpn", "dns", "ddns", "ntp", "share", "usb")):
            checks.append("check daemon config injection and service restart behavior")
        item = RouteCandidate(
            route=route,
            source=source,
            parameters=params,
            matched_keywords=matched,
            score=score,
            evidence_level=level,
            auth_class=auth_class,
            exposure=exposure,
            impact_class=impact_class,
            disposition=disposition,
            evidence=evidence,
            recommended_checks=checks,
        )
        if disposition.startswith("candidate:") and score >= 20:
            candidates.append(item)
        else:
            rejected.append(item)
    return (
        sorted(candidates, key=lambda item: (-item.score, item.route)),
        sorted(rejected, key=lambda item: (-item.score, item.route)),
    )


def _source_lines(rootfs: Path, source: str, strings_by_file: dict[str, list[str]]) -> list[str]:
    prefix, _, relative = source.partition(":")
    if prefix in {"string", "file"} and relative:
        candidate = str(rootfs / relative)
        if candidate in strings_by_file:
            return strings_by_file[candidate]
    return strings_by_file.get(source, [])


def _route_context(route: str, source: str, lines: list[str], radius: int = 12) -> list[str]:
    """Return route-adjacent strings for monolithic dispatchers.

    Standalone CGI/script files are already a useful handler boundary. For a
    route recovered from a large binary, use bounded neighborhoods around the
    route string so a sink elsewhere in ``httpd`` cannot promote it.
    """
    if source.startswith("file:"):
        return lines
    needles = {route.lower(), Path(route).name.lower()}
    indexes = [
        index
        for index, line in enumerate(lines)
        if any(needle and needle in line.lower() for needle in needles)
    ]
    if not indexes:
        return []
    selected: set[int] = set()
    for index in indexes:
        selected.update(range(max(0, index - radius), min(len(lines), index + radius + 1)))
    return [lines[index] for index in sorted(selected)]


def _classify_auth(route: str, source_text: str) -> tuple[str, list[str]]:
    text = f"{route}\n{source_text}"
    route_lower = route.lower()
    evidence: list[str] = []
    if PUBLIC_MARKERS.search(text):
        evidence.append("public/pre-authentication marker co-located with route")
        if any(token in route_lower for token in ("setup", "wizard", "onboard")):
            return "setup-only", evidence
        return "none", evidence
    if ADMIN_MARKERS.search(route_lower) and AUTH_MARKERS.search(source_text):
        evidence.append("administrative route and authentication markers are co-located")
        return "admin", evidence
    if AUTH_MARKERS.search(source_text):
        evidence.append("authentication/session marker is co-located; enforcement is unproven")
        return "required", evidence
    evidence.append("no authentication decision recovered")
    return "unknown", evidence


def _classify_route_exposure(route: str, source_text: str) -> str:
    text = f"{route}\n{source_text}".lower()
    if any(marker in text for marker in ("wan_access", "remote_management", "0.0.0.0")):
        return "wan/lan"
    if any(marker in text for marker in ("lan", "localhost", "127.0.0.1")):
        return "lan"
    return "unknown"


def _potential_impact(local_sinks: list[str], risky_params: list[str], mutating: bool) -> str:
    if any(name in local_sinks for name in ("system", "popen", "exec")) and risky_params:
        return "possible command execution"
    if "unsafe_copy" in local_sinks and risky_params:
        return "possible memory corruption"
    if "file_write" in local_sinks and risky_params:
        return "possible arbitrary/configuration write"
    if mutating:
        return "security-sensitive state change"
    return "unproven"


def _discover_services(rootfs: Path, strings_by_file: dict[str, list[str]]) -> list[ServiceSurface]:
    """Inventory high-value non-HTTP parsers from binaries and startup/config files."""
    found: dict[tuple[str, str], ServiceSurface] = {}
    for source, lines in strings_by_file.items():
        relative = _short_source(rootfs, Path(source)).removeprefix("string:")
        basename = Path(source).name.lower()
        text = "\n".join(lines).lower()
        for service, (protocol, exposure, auth, risk) in SERVICE_NAMES.items():
            if service not in basename and service not in text:
                continue
            evidence = ["service marker present"]
            local_sinks = sorted(name for name, pattern in SINK_PATTERNS.items() if pattern.search(text))
            if local_sinks:
                evidence.append(f"local sinks: {', '.join(local_sinks)}")
            key = (service, relative)
            found[key] = ServiceSurface(service, relative, protocol, exposure, auth, risk, evidence)
    return sorted(
        found.values(),
        key=lambda item: ({"high": 0, "medium": 1, "low": 2}[item.risk], item.service, item.source),
    )[:200]


def _version_applicability(version: str | None, vuln: KnownVulnerability) -> str:
    if not version:
        return "unknown tested version"
    normalized = _normalize_version(version)
    affected = {_normalize_version(item) for item in vuln.affected_versions}
    if normalized in affected:
        return "known affected version"
    if vuln.fixed_in and _compare_versions(normalized, _normalize_version(vuln.fixed_in)) >= 0:
        return "tested version appears newer than listed fixed version"
    if vuln.affected_versions or vuln.fixed_in:
        return "version not listed as known affected"
    return "product-family advisory; affected range not encoded"


def _normalize_version(version: str) -> str:
    match = re.search(r"(\d+(?:\.\d+){1,5})", version)
    return match.group(1) if match else version


def _compare_versions(left: str, right: str) -> int:
    left_parts = [int(part) for part in re.findall(r"\d+", left)]
    right_parts = [int(part) for part in re.findall(r"\d+", right)]
    width = max(len(left_parts), len(right_parts))
    left_parts.extend([0] * (width - len(left_parts)))
    right_parts.extend([0] * (width - len(right_parts)))
    return (left_parts > right_parts) - (left_parts < right_parts)


def _normalize_route(route: str) -> str:
    route = route.strip().strip("'\"")
    route = route.split("?", 1)[0]
    route = re.sub(r"^https?://[^/]+", "", route)
    route = route.lstrip("./")
    return route or "/"


def _short_source(rootfs: Path, path: Path) -> str:
    try:
        return f"string:{path.relative_to(rootfs)}"
    except ValueError:
        return f"string:{path}"


def _which_strings() -> str | None:
    for candidate in ("/usr/bin/strings", "/bin/strings"):
        if Path(candidate).exists():
            return candidate
    return None
