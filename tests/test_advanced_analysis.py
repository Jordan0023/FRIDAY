import tempfile
import unittest
from pathlib import Path

from netgear_firmware_audit.advanced_analysis import (
    RouteProof,
    archive_test_cases,
    auth_test_matrix,
    build_fuzz_seeds,
    classify_trace,
    confirmation_policy,
    correlate_flows,
    diff_fingerprints,
    discover_rootfs_candidates,
    generate_archive_corpus,
    safe_validation_recipes,
    variant_matches,
)
from netgear_firmware_audit.zero_day import analyze_zero_day_surface, render_zero_day_markdown


class AdvancedAnalysisTests(unittest.TestCase):
    def test_discovers_non_squashfs_root(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            base = Path(directory)
            root = base / "odd" / "ubifs-root" / "volume"
            for name in ("bin", "etc", "lib", "usr", "www"):
                (root / name).mkdir(parents=True, exist_ok=True)
            self.assertIn(root, discover_rootfs_candidates(base))

    def test_flow_requires_source_and_sink_in_same_file(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            base = Path(directory)
            a, b = str(base / "httpd"), str(base / "helper")
            flows = correlate_flows(base, {a: ["QUERY_STRING", "system(", "apply.cgi"], b: ["popen("]}, {a: ["apply.cgi"]})
            self.assertEqual(len(flows), 1)
            self.assertEqual(flows[0].confidence, "L3-correlated")

    def test_diff_and_recipes_are_bounded(self) -> None:
        self.assertEqual(diff_fingerprints({"a": "1"}, {"a": "2", "b": "3"})["changed"], ["a"])
        self.assertTrue(all(any("isolated" in rule for rule in recipe.restrictions) for recipe in safe_validation_recipes()))

    def test_global_sink_does_not_promote_unrelated_route(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "www").mkdir()
            (root / "bin").mkdir()
            (root / "etc").mkdir()
            (root / "lib").mkdir()
            (root / "usr").mkdir()
            (root / "www" / "status.cgi").write_text('<form action="status.cgi"><input name="host"></form>')
            (root / "bin" / "unrelated").write_text("QUERY_STRING system(")
            triage = analyze_zero_day_surface(root, "Test Router")
            self.assertFalse(any(item.route == "status.cgi" for item in triage.candidates))
            rejected = next(item for item in triage.rejected_candidates if item.route == "status.cgi")
            self.assertIn("not correlated", rejected.disposition)

    def test_pre_auth_local_sink_is_promoted_with_impact(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            for name in ("www", "bin", "etc", "lib", "usr"):
                (root / name).mkdir()
            handler = root / "www" / "unauth_ping.cgi"
            handler.write_text(
                '<form action="unauth_ping.cgi"><input name="host"></form>\n'
                "no_auth QUERY_STRING system("
            )
            triage = analyze_zero_day_surface(root, "Test Router")
            candidate = next(item for item in triage.candidates if item.route == "unauth_ping.cgi")
            self.assertEqual(candidate.auth_class, "none")
            self.assertEqual(candidate.evidence_level, "L3")
            self.assertEqual(candidate.impact_class, "possible command execution")

    def test_ghidra_function_local_evidence_enriches_matching_route_only(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            for name in ("www", "bin", "etc", "lib", "usr"):
                (root / name).mkdir()
            (root / "www" / "unauth_ping.cgi").write_text(
                '<form action="unauth_ping.cgi"><input name="host"></form>\nno_auth'
            )
            triage = analyze_zero_day_surface(
                root,
                "Test Router",
                ghidra_evidence=[{
                    "binary": "httpd",
                    "function": "handle_ping",
                    "address": "00102030",
                    "route": "unauth_ping.cgi",
                    "sink": "system",
                }],
            )
            candidate = next(item for item in triage.candidates if item.route == "unauth_ping.cgi")
            self.assertIn("system", candidate.evidence[-1])
            self.assertTrue(any("Ghidra function handle_ping" in item for item in candidate.evidence))

    def test_non_http_service_inventory_is_reported(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            for name in ("www", "bin", "etc", "lib", "usr"):
                (root / name).mkdir()
            (root / "etc" / "services.conf").write_text("miniupnpd system(")
            triage = analyze_zero_day_surface(root, "Test Router")
            self.assertTrue(any(item.service == "miniupnpd" for item in triage.service_surface))
            self.assertIn("Non-HTTP Service Surface", render_zero_day_markdown(triage))

    def test_missing_shared_memory_fault_is_not_security_crash(self) -> None:
        trace = """shmget(287454035,474104,438) = -1 errno=2 (No such file or directory)
shmat(-1,0,0) = -1 errno=22 (Invalid argument)
--- SIGSEGV {si_signo=SIGSEGV, si_code=1, si_addr=0x00015203} ---
"""
        result = classify_trace(trace)
        self.assertEqual(result.category, "emulation_dependency")
        self.assertFalse(result.security_relevant)
        self.assertEqual(result.fault_address, "0x00015203")

    def test_confirmation_requires_reproduced_effect_and_flow(self) -> None:
        proof = RouteProof("apply.cgi", network_reachable=True, handler_identified=True)
        self.assertEqual(proof.level, "L2")
        self.assertFalse(proof.confirmed)
        proof.parameter_to_sink_proven = True
        proof.auth_decision_proven = True
        proof.security_effect_reproduced = True
        self.assertEqual(proof.level, "L5")
        self.assertTrue(proof.confirmed)
        policy = confirmation_policy()
        self.assertEqual(policy["confirmed_label_requires"], "L5")
        self.assertFalse(policy["vendor_contact_required"])
        self.assertIn("documented, dated public-prior-art search", policy["confirmed_zero_day_requires"])
        self.assertIn(
            "novel reproducible pre-authentication exploitation path with no remote administrator session required",
            policy["confirmed_zero_day_requires"],
        )
        self.assertEqual(
            policy["authenticated_admin_disposition"],
            "confirmed vulnerability, but not a confirmed zero-day",
        )

    def test_auth_fuzz_and_archive_cases_cover_required_states(self) -> None:
        self.assertEqual([case.name for case in auth_test_matrix()], ["no_credentials", "invalid_session", "low_privilege"])
        seeds = build_fuzz_seeds(["soap/server_sa", "upload.cgi"], {"upload.cgi": ["filename"]})
        self.assertTrue(any(seed.protocol == "soap" for seed in seeds))
        self.assertTrue(any(seed.protocol == "multipart" for seed in seeds))
        self.assertIn("symlink_pivot", {case.name for case in archive_test_cases()})

    def test_archive_corpus_and_cross_product_variants(self) -> None:
        with tempfile.TemporaryDirectory() as directory:
            base = Path(directory)
            corpus = generate_archive_corpus(base / "corpus")
            self.assertTrue(any(path.name == "symlink_pivot.tar" for path in corpus))
            left, right = base / "left", base / "right"
            for root in (left, right):
                (root / "bin").mkdir(parents=True)
                executable = root / "bin" / "httpd"
                executable.write_bytes(b"\x7fELF" + b"\0" * 16)
                executable.chmod(0o755)
            matches = variant_matches({"left": left, "right": right})
            self.assertEqual(len(matches), 1)


if __name__ == "__main__":
    unittest.main()
